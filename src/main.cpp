#include "../settings/compile_time_settings.h"
#include "../include/kernel/CPU_kernel/creature.h"

#include <iostream>

int main() {
    //std::cout << static_cast<int>(Policies::extractor.map.checkAnd(Policies::CreatureAttributes::Direction::Eight, Policies::Commands::Begin::Off)) << '\n';
    //std::cout << Policies::extractor.getNum<Policies::Commands::Rotate>() << '\n';
    std::cout << CPUKernel::config.idx<Policies::Commands::Rotate> << '\n';
}