#include "UnitTests.hpp"
#include "Triangle.hpp"

void testTriangleArea() {
    Triangle triangle(3.0, 4.0, 5.0);
    ASSERT_EQ(triangle.calculateArea(), 6.0);
}

int main() {
    UnitTests tests;

    tests.addTest("Triangle Area Calculation", testTriangleArea);

    tests.run();

    return 0;
}
