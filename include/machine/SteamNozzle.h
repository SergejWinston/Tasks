#ifndef STEAM_NOZZLE_H
#define STEAM_NOZZLE_H

#include "MachinePart.h"
#include "../ingredients/WetIngredient.h"
#include "../ingredients/DryIngredient.h"

class SteamNozzle : public MachinePart {
public:
    SteamNozzle() : MachinePart("Форсунка") {}

    int process(const Ingredient& ingredient) const override {
        if (ingredient.isCoffee())
            return 0;

        if (ingredient.isWet()) {
            const auto& wet = static_cast<const WetIngredient&>(ingredient);
            if (wet.getTargetTemperature() > 0 && wet.getTargetTemperature() < 100.0)
                return wet.getPreparationTime();
            return 0;
        }

        const auto& dry = static_cast<const DryIngredient&>(ingredient);
        return dry.getPreparationTime();
    }
};

#endif
