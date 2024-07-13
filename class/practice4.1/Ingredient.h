#pragma once

#include <string>

class Ingredient {
public:
    Ingredient(const std::string& name, double cost) : name(name), cost(cost) {}

    std::string getName() const { return name; }
    double getCost() const { return cost; }

private:
    std::string name;
    double cost;
};

