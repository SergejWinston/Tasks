#ifndef COFFEE_MACHINE_H
#define COFFEE_MACHINE_H

#include "Grinder.h"
#include "BrewingGroup.h"
#include "Boiler.h"
#include "SteamNozzle.h"
#include "../recipe/Recipe.h"
#include "../DrinkResult.h"

#include <algorithm>
#include <iostream>

class CoffeeMachine {
public:
    DrinkResult prepare(const Recipe& recipe) const {
        int coffeeTime = 0;
        int boilerTime = 0;
        int nozzleTime = 0;

        for (const auto& ingredient : recipe.getIngredients()) {
            int grindTime = grinder_.process(*ingredient);
            int brewTime = brewingGroup_.process(*ingredient);
            coffeeTime += grindTime + brewTime;

            boilerTime += boiler_.process(*ingredient);
            nozzleTime += nozzle_.process(*ingredient);
        }

        int totalTime = std::max({coffeeTime, boilerTime, nozzleTime});
        return {recipe.getName(), totalTime};
    }

private:
    Grinder grinder_;
    BrewingGroup brewingGroup_;
    Boiler boiler_;
    SteamNozzle nozzle_;
};

#endif
