#ifndef PIZZA_H
#define PIZZA_H

#include <vector>
#include <print>
#include "Ingredient.h"

class Pizza {
public:
    Pizza(const std::vector<Ingredient>& ingredients) : ingredients(ingredients) {}

    void showIngredients() const {
        for (const auto& ingredient : ingredients) {
            std::println("{} - ${}", ingredient.getName(), ingredient.getCost());
        }
    }

    double getCost() const {
        double total = 0;
        for (const auto& ingredient : ingredients) {
            total += ingredient.getCost();
        }
        return total;
    }

private:
    std::vector<Ingredient> ingredients;
};

#endif 
