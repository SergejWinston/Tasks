#ifndef BOILER_H
#define BOILER_H

#include "MachinePart.h"
#include "../ingredients/WetIngredient.h"

class Boiler : public MachinePart {
public:
    Boiler() : MachinePart("Бойлер") {}

    int process(const Ingredient& ingredient) const override {
        if (!ingredient.isWet() || ingredient.isCoffee())
            return 0;
        const auto& wet = static_cast<const WetIngredient&>(ingredient);
        if (wet.getTargetTemperature() >= 100.0)
            return wet.getPreparationTime();
        return 0;
    }
};

#endif
