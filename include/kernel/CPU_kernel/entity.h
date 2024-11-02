#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <stdint.h>

struct Entity {
    int x;
    int y;
    uint32_t color;

    Entity(int x, int y, uint32_t color): x(x), y(y), color(color) {};
};

#endif