#ifndef BREWING_GROUP_H
#define BREWING_GROUP_H

#include "MachinePart.h"
#include "../ingredients/CoffeeBean.h"

class BrewingGroup : public MachinePart {
public:
    BrewingGroup() : MachinePart("Группа заваривания") {}

    int process(const Ingredient& ingredient) const override {
        if (!ingredient.isCoffee())
            return 0;
        const auto& coffee = static_cast<const CoffeeBean&>(ingredient);
        return coffee.getBrewTime();
    }
};

#endif
