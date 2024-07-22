#include "Rectangle.hpp"

Rectangle::Rectangle(double width, double height)
    : width(width), height(height) {}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::biggerSide() const {
    return (width > height) ? width : height;
}

bool Rectangle::canBePlacedInside(const Rectangle& other) const {
    return width <= other.width && height <= other.height;
}
