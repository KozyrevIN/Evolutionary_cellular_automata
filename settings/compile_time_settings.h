#ifndef cell_attributes_header
    #define cell_attributes_header
    #include "../include/concept/cell_attributes.h"
#endif

#ifndef object_attributes_header
    #define object_attributes_header
    #include "../include/concept/object_attributes.h"
#endif

#ifndef creature_attributes_header
    #define creature_attributes_header
    #include "../include/concept/creature_attributes.h"
#endif


enum class Attribute: uint8_t {
    energy,
    direction,
}