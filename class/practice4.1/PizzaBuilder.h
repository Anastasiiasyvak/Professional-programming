#pragma once

#include <vector>
#include "Ingredient.h"
#include "Pizza.h"

class PizzaBuilder {
public:
    void addIngredient(const Ingredient& ingredient) {
        ingredients.push_back(ingredient);
    }

    [[nodiscard]] Pizza build() {
        Pizza pizza(std::move(ingredients));
        ingredients.clear();
        return pizza;
    }

private:
    std::vector<Ingredient> ingredients;
};

