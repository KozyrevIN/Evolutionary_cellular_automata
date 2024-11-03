#ifndef POLICIES_H
#define POLICIES_H

#include "enum_map.h"

namespace Policies 
{

namespace CellAttributes 
{
    enum class Nutrients { Off, On };
}

namespace ObjectAttributes
{

}

namespace CreatureAttributes
{
    enum class Direction { Four, Eight, Off };
}

namespace Commands 
{
    enum class Begin { Off, On };

    enum class End { Off, On };

    enum class Eat { Off, On };

    enum class Rotate { Off, On };

    enum class Divide { Off, On };
}

template<auto... enums>
class PolicyMap : public EnumMap<enums...> {
    
    static_assert(EnumMap<enums...>::checkImplication(Commands::Eat::On, CellAttributes::Nutrients::On),
                  "Command 'Eat' requires cell attribute 'Nutrients'!");
};

}

#endif