#ifndef SYRUP_H
#define SYRUP_H

#include "WetIngredient.h"

class Syrup : public WetIngredient {
public:
    explicit Syrup(int portions = 1)
        : WetIngredient("сироп", portions, 0.0) {}
};

#endif
