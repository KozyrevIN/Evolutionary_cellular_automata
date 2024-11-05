#ifndef COMPILE_TIME_SETTINGS_H
#define COMPILE_TIME_SETTINGS_H

#include "../include/concept/policies.h"

namespace Policies
{
    constexpr static PolicyMap<
    CreatureAttributes::Direction::Off,
    Commands::Begin::On,
    CellAttributes::Nutrients::Off,
    Commands::End::Off,
    Commands::Rotate::On
    > policy_map;
}

#endif