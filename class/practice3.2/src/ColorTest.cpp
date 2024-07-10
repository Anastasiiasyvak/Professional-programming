#include "UnitTests.hpp"
#include "Color.hpp"

void testMagicColorGeneration() {
    Color color(100, 150, 200);
    color.generateMagicColor();

    ASSERT_EQ(color.getRed(), 49);
    ASSERT_EQ(color.getGreen(), 298);
    ASSERT_EQ(color.getBlue(), 200);
}

int main() {
    UnitTests tests;

    tests.addTest("Magic Color Generation", testMagicColorGeneration);

    tests.run();

    return 0;
}
