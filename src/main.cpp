#include "recipe/RecipeRepository.h"
#include "machine/CoffeeMachine.h"
#include "Display.h"

int main() {
    RecipeRepository repository("data/recipes.txt");
    CoffeeMachine machine;
    std::vector<DrinkResult> results;
    for (const auto& recipe : repository.getRecipes())
        results.push_back(machine.prepare(recipe));
    Display::show(results);
    return 0;
}
