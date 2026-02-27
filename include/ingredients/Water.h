#ifndef WATER_H
#define WATER_H

#include "WetIngredient.h"

class Water : public WetIngredient {
public:
    explicit Water(int portions = 1)
        : WetIngredient("вода", portions, 100.0) {}
};

#endif
