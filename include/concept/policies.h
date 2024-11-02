#ifndef POLICIES_H
#define POLICIES_H

namespace Policies 
{
    //cell attributes
    namespace CellAttributes 
    {
        enum class Nutrients {
            On,
            Off
        };
    }

    //object attributes
    namespace ObjectAttributes
    {

    }

    //creature attributes
    namespace CreatureAttributes
    {
        enum class Direction {
            Four,
            Eight,
            Off,
        };

        enum class Memory {
            Off,
            On
        };
    }

    //commands
    namespace Commands 
    {
        enum class Begin {
            Off,
            On
        };

        enum class End {
            Off,
            On,
        };
    }
}

#endif