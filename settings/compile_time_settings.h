#ifndef COMPILE_TIME_SETTINGS_H
#define COMPILE_TIME_SETTINGS_H

#include "../include/concept/policies.h"

namespace Policies
{
    constexpr static PolicyMap<
    Commands::Begin::On,
    CellAttributes::Nutrients::Off,
    Commands::End::On,
    Commands::Rotate::Off
    > policy_map;
}

#endif