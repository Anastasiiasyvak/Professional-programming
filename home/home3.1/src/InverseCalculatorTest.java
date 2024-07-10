import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

public class InverseCalculatorTest {

    @Test
    void testInverseOfProduct() {
        InverseCalculator calculator = new InverseCalculator();
        double result = calculator.inverse(2, 3, 4);
        assertEquals(1.0 / (2 * 3 * 4), result);
    }

    @Test
    void testSumAsZero() {
        InverseCalculator calculator = new InverseCalculator();
        double result = calculator.inverse(-1, 0, 1);
        assertEquals(-1 + (0 + 1) * (1 - 1), result);
    }

    @Test
    void testProductAsZero() {
        InverseCalculator calculator = new InverseCalculator();
        double result = calculator.inverse(0, 1, 2);
        assertEquals(1.0 / (0 + 1 + 2), result);
    }

    @Test
    void testBothZeroCases() {
        InverseCalculator calculator = new InverseCalculator();
        double result = calculator.inverse(0, 0, 0);
        assertEquals(0 + (0 + 1) * (0 - 1), result);
    }
}
