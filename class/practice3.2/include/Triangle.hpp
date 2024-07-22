#pragma once

class Triangle {
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    double calculateArea() const {
        double s = (a + b + c) / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

private:
    double a, b, c;
};
