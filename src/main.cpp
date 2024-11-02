#include "../settings/compile_time_settings.h"

#include <iostream>

int main() {
    std::cout << static_cast<int>(Policies::options.getValue<Policies::CreatureAttributes::Direction>()) << '\n';
}