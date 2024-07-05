#pragma once
#include <string>

class BaseMegaCalculator {
public:
    virtual ~BaseMegaCalculator() = default;
    virtual double getPrice() const = 0;
    virtual double getMinimalValue() const = 0;
    virtual std::string getReport() const = 0;
};

class MyCoolCalculator : public BaseMegaCalculator {
public:
    MyCoolCalculator(double a, double b, double c) : a(a), b(b), c(c) {}

    double getPrice() const override {
        return a + b + c;
    }

    double getMinimalValue() const override {
        return a < b ? (a < c ? a : c) : (b < c ? b : c);
    }

    std::string getReport() const override {
        return std::format("MyCoolCalculator with a={}, b={}, c={}", a, b, c);
    }

private:
    double a, b, c;
};

class ConstantCalculator : public BaseMegaCalculator {
public:
    double getPrice() const override {
        return 42.0;
    }

    double getMinimalValue() const override {
        return 0.0;
    }

    std::string getReport() const override {
        return "ConstantCalculator with a constant value";
    }
};
