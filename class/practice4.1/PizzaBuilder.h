#ifndef PIZZABUILDER_H
#define PIZZABUILDER_H

#include <vector>
#include "Ingredient.h"
#include "Pizza.h"

class PizzaBuilder {
public:
    void addIngredient(const Ingredient& ingredient) {
        ingredients.push_back(ingredient);
    }

    Pizza build() {
        return Pizza(ingredients);
    }

private:
    std::vector<Ingredient> ingredients;
};

#endif 
