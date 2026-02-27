#ifndef GRINDER_H
#define GRINDER_H

#include "MachinePart.h"
#include "../ingredients/CoffeeBean.h"

class Grinder : public MachinePart {
public:
    Grinder() : MachinePart("Кофемолка") {}

    int process(const Ingredient& ingredient) const override {
        if (!ingredient.isCoffee())
            return 0;
        const auto& coffee = static_cast<const CoffeeBean&>(ingredient);
        return coffee.getGrindTime();
    }
};

#endif
