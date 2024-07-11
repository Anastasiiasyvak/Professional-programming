#include "Rectangle.hpp"
#include "UnitTests.hpp"
#include <stdexcept>
#include <print>

void testRectangleArea() {
    Rectangle r1(3.0, 4.0);
    ASSERT_EQ(r1.area(), 12.0);

    Rectangle r2(5.0, 6.0);
    ASSERT_EQ(r2.area(), 30.0);
}

void testRectangleBiggerSide() {
    Rectangle r1(3.0, 4.0);
    ASSERT_EQ(r1.biggerSide(), 4.0);

    Rectangle r2(6.0, 5.0);
    ASSERT_EQ(r2.biggerSide(), 6.0);
}

void testRectanglePlacement() {
    Rectangle r1(3.0, 4.0);
    Rectangle r2(5.0, 6.0);
    ASSERT_EQ(r1.canBePlacedInside(r2), true);
    ASSERT_EQ(r2.canBePlacedInside(r1), false);
}

int main() {
    UnitTests tests;
    tests.addTest("testRectangleArea", testRectangleArea);
    tests.addTest("testRectangleBiggerSide", testRectangleBiggerSide);
    tests.addTest("testRectanglePlacement", testRectanglePlacement);
    tests.run();
    return 0;
}
