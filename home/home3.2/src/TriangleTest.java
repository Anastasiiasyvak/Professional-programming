import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class TriangleTest {

    @Test
    public void testTriangleArea() {
        Triangle triangle = new Triangle(3, 4, 5);
        assertEquals(6, triangle.calculateArea(), 0.001);
    }

    @Test
    public void testAnotherTriangleArea() {
        Triangle triangle = new Triangle(6, 8, 10);
        assertEquals(24, triangle.calculateArea(), 0.001);
    }

    @Test
    public void testInvalidTriangleArea() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Triangle(0, 4, 5);
        });
    }

    @Test
    public void testHeightForSideA() {
        Triangle triangle = new Triangle(3, 4, 5);
        assertEquals(4, triangle.getHeight("a"), 0.001);
    }

    @Test
    public void testHeightForSideB() {
        Triangle triangle = new Triangle(3, 4, 5);
        assertEquals(3, triangle.getHeight("b"), 0.001);
    }

    @Test
    public void testHeightForSideC() {
        Triangle triangle = new Triangle(3, 4, 5);
        assertEquals(2.4, triangle.getHeight("c"), 0.001);
    }

    @Test
    public void testInvalidHeightArgument() {
        Triangle triangle = new Triangle(3, 4, 5);
        assertThrows(IllegalArgumentException.class, () -> {
            triangle.getHeight("d");
        });
    }
}
