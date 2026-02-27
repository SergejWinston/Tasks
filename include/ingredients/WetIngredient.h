#ifndef WET_INGREDIENT_H
#define WET_INGREDIENT_H

#include "Ingredient.h"

class WetIngredient : public Ingredient {
public:
    WetIngredient(const std::string& name, int portions,
                  double targetTemp, double initialTemp = 24.0)
        : Ingredient(name, portions, initialTemp),
          targetTemperature_(targetTemp) {}

    bool isWet() const override { return true; }

    int getPreparationTime() const override {
        if (targetTemperature_ <= temperature_)
            return 0;
        return static_cast<int>(targetTemperature_ - temperature_) * portions_;
    }

    double getTargetTemperature() const { return targetTemperature_; }

protected:
    double targetTemperature_;
};

#endif
