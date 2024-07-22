#include <print>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include "Ingredient.h"
#include "Pizza.h"
#include "PizzaBuilder.h"

void loadIngredients(const std::string& filename, std::unordered_map<std::string, double>& ingredients) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::println("Could not open the file!");
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t delimiterPos = line.find(" - ");
        if (delimiterPos == std::string::npos) {
            std::println("Incorrect format in line: {}", line);
            continue;
        }
        std::string name = line.substr(0, delimiterPos);
        double cost;
        try {
            cost = std::stod(line.substr(delimiterPos + 3));
        } catch (const std::invalid_argument& e) {
            std::println("Invalid cost in line: {}", line);
            continue;
        }
        ingredients[name] = cost;
    }

    file.close();
}

int main() {
    constexpr const char* filename = "ingredients.txt";
    std::unordered_map<std::string, double> ingredients;
    loadIngredients(filename, ingredients);

    PizzaBuilder builder;
    std::string input;
    constexpr std::string_view doneCommand = "done";

    while (true) {
        std::println("Available ingredients:");
        for (const auto& [ingredientName, ingredientCost] : ingredients) {
            std::println("{} - ${}", ingredientName, ingredientCost);
        }
        std::println("Enter an ingredient or type '{}' to finish: ", doneCommand);
        std::getline(std::cin, input);

        if (input == doneCommand) break;

        if (ingredients.find(input) != ingredients.end()) {
            builder.addIngredient(Ingredient(input, ingredients[input]));
        } else {
            std::println("Ingredient not found!");
        }
    }

    Pizza pizza = builder.build();
    std::println("Your pizza contains:");
    pizza.showIngredients();
    std::println("Total cost: ${}", pizza.getCost());

    return 0;
}

