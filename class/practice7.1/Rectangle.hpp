#pragma once

class Rectangle {
public:
    Rectangle(double width, double height);
    double area() const;
    double biggerSide() const;
    bool canBePlacedInside(const Rectangle& other) const;

private:
    double width;
    double height;
};
