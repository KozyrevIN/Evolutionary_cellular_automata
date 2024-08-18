#include <stdint.h>

#ifndef entity_header
    #define entity_header
    #include "entity.h"
#endif

using command_num = uint8_t;

struct Creature: public Entity {
private:
    virtual void setEnergy(...) {};
    virtual void setMemory(...) {};

public:
    std::vector<Commands> dna;
    

    Creature(int x, int y) : Entity(x, y) {};
};