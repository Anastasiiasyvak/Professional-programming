public class Triangle {
    private double a, b, c;

    public Triangle(double a, double b, double c) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
            throw new IllegalArgumentException("Invalid triangle sides");
        }
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double calculateArea() {
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    public double getHeight(String side) {
        double area = calculateArea();
        switch (side) {
            case "a":
                return 2 * area / a;
            case "b":
                return 2 * area / b;
            case "c":
                return 2 * area / c;
            default:
                throw new IllegalArgumentException("Invalid side argument");
        }
    }
}
