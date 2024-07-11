#include <iostream>
#include <print>
#include "Rectangle.hpp"

int main() {
    double widths[5] = {0.0};
    double heights[5] = {0.0};
    int count = 0;
    double biggestArea = 0;
    double smallestArea = 1000000;

    for (int i = 0; i < 5; ++i) {
        std::println("Enter rectangle {}: ", i + 1);
        if (std::cin >> widths[i] >> heights[i]) {
            Rectangle rect(widths[i], heights[i]);
            double area = rect.area();
            count++;
            if (area > biggestArea) {
                biggestArea = area;
            }
            if (area < smallestArea) {
                smallestArea = area;
            }
        }
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i != j) {
                Rectangle r1(widths[i], heights[i]);
                Rectangle r2(widths[j], heights[j]);
                if (r1.canBePlacedInside(r2)) {
                    std::println("Rectangle {} can be placed inside Rectangle {}", i + 1, j + 1);
                }
            }
        }
    }

    std::println("The biggest area: {}", biggestArea);
    std::println("Number of rectangles: {}", count);
    std::println("The smallest area: {}", smallestArea);

    for (int i = 0; i < 5; ++i) {
        Rectangle rect(widths[i], heights[i]);
        std::println("The biggest side of rectangle {}: {}", i + 1, rect.biggerSide());
    }

    double totalArea = 0;
    for (int i = 0; i < 5; ++i) {
        Rectangle rect(widths[i], heights[i]);
        totalArea += rect.area();
    }
    std::println("Total area of rectangles: {}", totalArea);

    return 0;
}
