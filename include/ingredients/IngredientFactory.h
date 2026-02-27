#ifndef INGREDIENT_FACTORY_H
#define INGREDIENT_FACTORY_H

#include "Ingredient.h"
#include "Water.h"
#include "Milk.h"
#include "Cream.h"
#include "Syrup.h"
#include "Brandy.h"
#include "CoffeeBean.h"
#include "Sugar.h"
#include "VanillaSugar.h"
#include "Cinnamon.h"

#include <memory>
#include <string>
#include <stdexcept>

class IngredientFactory {
public:
    static std::unique_ptr<Ingredient> create(const std::string& name, int portions) {
        if (name == "кофе")
            return std::make_unique<CoffeeBean>(portions);
        if (name == "вода")
            return std::make_unique<Water>(portions);
        if (name == "молоко")
            return std::make_unique<Milk>(portions);
        if (name == "сливки")
            return std::make_unique<Cream>(portions);
        if (name == "сироп")
            return std::make_unique<Syrup>(portions);
        if (name == "бренди")
            return std::make_unique<Brandy>(portions);
        if (name == "сахар")
            return std::make_unique<Sugar>(portions);
        if (name == "ванильный сахар")
            return std::make_unique<VanillaSugar>(portions);
        if (name == "корица")
            return std::make_unique<Cinnamon>(portions);

        throw std::invalid_argument("Неизвестный ингредиент: " + name);
    }
};

#endif
