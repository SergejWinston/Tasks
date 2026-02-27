#ifndef CINNAMON_H
#define CINNAMON_H

#include "DryIngredient.h"

class Cinnamon : public DryIngredient {
public:
    explicit Cinnamon(int portions = 1)
        : DryIngredient("корица", portions, 3) {}
};

#endif
