#ifndef RECIPE_H
#define RECIPE_H

#include "../ingredients/Ingredient.h"
#include <string>
#include <vector>
#include <memory>
#include <utility>

class Recipe {
public:
    Recipe(const std::string& name,
           std::vector<std::unique_ptr<Ingredient>> ingredients)
        : name_(name), ingredients_(std::move(ingredients)) {}

    const std::string& getName() const { return name_; }

    const std::vector<std::unique_ptr<Ingredient>>& getIngredients() const {
        return ingredients_;
    }

private:
    std::string name_;
    std::vector<std::unique_ptr<Ingredient>> ingredients_;
};

#endif
