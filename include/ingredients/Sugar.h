#ifndef SUGAR_H
#define SUGAR_H

#include "DryIngredient.h"

class Sugar : public DryIngredient {
public:
    explicit Sugar(int portions = 1)
        : DryIngredient("сахар", portions, 5) {}
};

#endif
