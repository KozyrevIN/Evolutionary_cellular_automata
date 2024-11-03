#include "../settings/compile_time_settings.h"
#include "../include/kernel/CPU_kernel/creature.h"

#include <iostream>

int main() {
    std::cout << static_cast<int>(Policies::config.checkAnd(Policies::CreatureAttributes::Direction::Eight, Policies::Commands::Begin::Off)) << '\n';
}