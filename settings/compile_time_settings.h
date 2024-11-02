#ifndef COMPILE_TIME_SETTINGS_H
#define COMPILE_TIME_SETTINGS_H

#include "../include/concept/policies.h"
#include "../include/concept/enum_map.h"

namespace Policies
{
    constexpr static EnumMap<
    CreatureAttributes::Memory::On,
    CreatureAttributes::Direction::Off,
    CellAttributes::Nutrients::Off
    > options;
}

#endif