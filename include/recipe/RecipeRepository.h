#ifndef RECIPE_REPOSITORY_H
#define RECIPE_REPOSITORY_H

#include "Recipe.h"
#include "../ingredients/IngredientFactory.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

class RecipeRepository {
public:
    explicit RecipeRepository(const std::string& filePath) {
        loadFromFile(filePath);
    }

    const std::vector<Recipe>& getRecipes() const { return recipes_; }

private:
    std::vector<Recipe> recipes_;

    static std::string trim(const std::string& s) {
        auto start = s.find_first_not_of(" \t\r\n");
        if (start == std::string::npos) return "";
        auto end = s.find_last_not_of(" \t\r\n");
        return s.substr(start, end - start + 1);
    }

    void loadFromFile(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open())
            throw std::runtime_error("Не удалось открыть файл: " + filePath);

        std::string line;
        while (std::getline(file, line)) {
            line = trim(line);
            if (line.empty())
                continue;

            if (line.front() == '[' && line.back() == ']') {
                std::string name = line.substr(1, line.size() - 2);
                std::vector<std::unique_ptr<Ingredient>> ingredients;

                while (std::getline(file, line)) {
                    line = trim(line);
                    if (line.empty())
                        break;

                    auto lastSpace = line.rfind(' ');
                    if (lastSpace == std::string::npos)
                        throw std::runtime_error("Неверный формат строки: " + line);

                    std::string ingredientName = trim(line.substr(0, lastSpace));
                    int portions = std::stoi(line.substr(lastSpace + 1));

                    ingredients.push_back(
                        IngredientFactory::create(ingredientName, portions));
                }

                recipes_.emplace_back(name, std::move(ingredients));
            }
        }
    }
};

#endif
