#ifndef DRY_INGREDIENT_H
#define DRY_INGREDIENT_H

#include "Ingredient.h"

class DryIngredient : public Ingredient {
public:
    DryIngredient(const std::string& name, int portions,
                  int dissolveTimePerPortion, double initialTemp = 24.0)
        : Ingredient(name, portions, initialTemp),
          dissolveTime_(dissolveTimePerPortion) {}

    bool isWet() const override { return false; }

    int getPreparationTime() const override {
        return dissolveTime_ * portions_;
    }

    int getDissolveTime() const { return dissolveTime_; }

protected:
    int dissolveTime_;
};

#endif
