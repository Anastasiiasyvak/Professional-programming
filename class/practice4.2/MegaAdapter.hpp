#pragma once
#include "ModernCalculators.hpp"
#include "LegacyCalculator.hpp"

class MegaAdapter : public BaseMegaCalculator {
public:
    MegaAdapter(std::unique_ptr<LegacyCalculator> legacyCalculator)
        : legacyCalculator(std::move(legacyCalculator)) {}

    double getPrice() const override {
        return legacyCalculator->calculatePricePart1() + legacyCalculator->calculatePricePart2();
    }

    double getMinimalValue() const override {
        return legacyCalculator->getOurTheMostAndMinimalValue();
    }

    std::string getReport() const override {
        return legacyCalculator->getSomeDocumentRepresentation();
    }

private:
    std::unique_ptr<LegacyCalculator> legacyCalculator;
};
