#ifndef VANILLA_SUGAR_H
#define VANILLA_SUGAR_H

#include "DryIngredient.h"

class VanillaSugar : public DryIngredient {
public:
    explicit VanillaSugar(int portions = 1)
        : DryIngredient("ванильный сахар", portions, 5) {}
};

#endif
