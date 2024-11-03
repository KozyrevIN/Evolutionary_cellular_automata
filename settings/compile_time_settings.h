#ifndef COMPILE_TIME_SETTINGS_H
#define COMPILE_TIME_SETTINGS_H

#include "../include/concept/policies.h"

namespace Policies
{
    constexpr static PolicyMap<
    CreatureAttributes::Direction::Off,
    CellAttributes::Nutrients::Off
    > config;
}

#endif