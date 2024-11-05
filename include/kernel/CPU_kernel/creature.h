#ifndef CREATURE_H
#define CREATURE_H

#include <vector>

#include "entity.h"
#include "extractor.h"

class Supervisor;

template <CPUKernel::Extractor extractor>
struct CreatureTemplate : public Entity {
    int energy;

    // reatureTemplate(int x, int y, uint32_t color, const std::vector<Commands>
    // dna): Entity(x, y, color), dna(dna) {}; auto&& getClone(uint32_t seed);
};

using Creature = CreatureTemplate<CPUKernel::config>;

#endif