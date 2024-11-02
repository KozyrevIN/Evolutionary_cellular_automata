#ifndef CREATURES_HEADER
#define CREATURES_HEADER

#include <vector>
#include <boost/hana.hpp>
namespace hana = boost::hana;

#include "entity.h"
#include "../../../settings/compile_time_settings.h"

//direction attribute
struct DirectionPolicy {
    int8_t direction;

    DirectionPolicy() {};
    DirectionPolicy(int8_t direction): direction(direction) {};
};

struct NoDirectionPolicy {

};

//memory attribute
struct MemoryPolicy {
    int8_t memory;

    MemoryPolicy() {};
    MemoryPolicy(int8_t memory): memory(memory) {};
};

struct NoMemoryPolicy {

};

//creature class
template 
<
    class DirectionPolicy,
    class MemoryPolicy
>
struct CreatureTemplate: public Entity, DirectionPolicy, MemoryPolicy {
    std::vector<Commands> dna;
    int energy;

    CreatureTemplate(int x, int y, uint32_t color, const std::vector<Commands> dna): Entity(x, y, color), dna(dna) {};
    auto&& getClone(uint32_t seed);  
};

static constexpr bool direction_is_used = hana::contains(USED_CREATURE_ATTRIBUTES, CreatureAttributes::direction);
static constexpr bool memory_is_used = hana::contains(USED_CREATURE_ATTRIBUTES, CreatureAttributes::memory);

using Creature = CreatureTemplate
<
decltype(hana::if_(hana::bool_c<direction_is_used>, hana::type_c<DirectionPolicy>, hana::type_c<NoDirectionPolicy>))::type,
decltype(hana::if_(hana::bool_c<memory_is_used>, hana::type_c<MemoryPolicy>, hana::type_c<NoMemoryPolicy>))::type
>;

#endif