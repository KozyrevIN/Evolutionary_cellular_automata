#ifndef COMMANDS_HEADER
#define COMMANDS_HEADER

#include <stdint.h>

/*
 * Commands are elements of creature DNA. The implementation of commands is contained inside the kernel, this is an app-wide
 * abstraction used to define initial settings and pass info to kernel. Also it contains description of each action, attributes
 * that are necessary to perform this action and attributes that may change how this action is performed. It's worths noting
 * that execution of commands continues until dna ends (then on the next turn it will be read from beginning) or command
 * itself will terminate the process of dna reading and command execution. The general rule is that process of reading DNA is
 * terminated when "physical" state of any creature or object is altered, but it's not necessary. The point of this is that
 * creatures "think" immideately, but to move, jump, eat e.t.c they need some time.
 * 
 * There are alaso several rules all commands MUST follow:
 * 1. Local interaction. Execution of the command mustn't change state of any cells and objects
 *    which position isn't in Moore's neighbourhood of cell initially containing the creature.
 * 2. Each command outputs int value. This value is then passed as input to next command.
 **/

enum class Commands: uint8_t {
    /*
     * begin
     * Outputs 1. May be used as a starting point for new command sequence (aka gene).
     * @necessary_attributes: none
     **/
    begin,
    /*
     * end
     * Outputs 0. May be used as a end point for new command sequence (aka gene).
     * @necessary_attributes: none
     **/
    end,

    comp_1,
    add_1,
    sub_1,
    mul_2,
    div_2,
    random,
    count_empty_adjacent,

    rotate,
    /*
     * rotate
     * Changes direction: new direction = old direction + input. Outputs input.
     * @necessary_attributes: direction
     **/
    move,
    photosynthesize,
    clone,
    attack,
    eat
};

#endif