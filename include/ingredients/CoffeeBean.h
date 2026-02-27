#ifndef COFFEE_BEAN_H
#define COFFEE_BEAN_H

#include "DryIngredient.h"

class CoffeeBean : public DryIngredient {
public:
    static constexpr int GRIND_TIME = 16;
    static constexpr int BREW_TIME = 22;

    explicit CoffeeBean(int portions = 1)
        : DryIngredient("кофе", portions, 0) {}

    bool isCoffee() const override { return true; }

    int getPreparationTime() const override {
        return (GRIND_TIME + BREW_TIME) * portions_;
    }

    int getGrindTime() const { return GRIND_TIME * portions_; }
    int getBrewTime() const { return BREW_TIME * portions_; }
};

#endif
