#include <cassert>
#include "Ingredient.h"
#include "PizzaBuilder.h"
#include "Pizza.h"
#include <print>

void testIngredient() {
    Ingredient ingredient("tomatoes", 15.0);
    assert(ingredient.getName() == "tomatoes");
    assert(ingredient.getCost() == 15.0);
    std::println("testIngredient passed");
}

void testPizzaBuilder() {
    PizzaBuilder builder;
    builder.addIngredient(Ingredient("tomatoes", 15.0));
    builder.addIngredient(Ingredient("cheese", 20.0));
    Pizza pizza = builder.build();
    assert(pizza.getCost() == 35.0);
    std::println("testPizzaBuilder passed");
}

void testPizza() {
    std::vector<Ingredient> ingredients = { Ingredient("tomatoes", 15.0), Ingredient("cheese", 20.0) };
    Pizza pizza(ingredients);
    assert(pizza.getCost() == 35.0);
    std::println("testPizza passed");
}

int main() {
    testIngredient();
    testPizzaBuilder();
    testPizza();
    std::println("All tests passed!");
    return 0;
}
