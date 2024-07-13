public class MyCoolCalculator extends BaseMegaCalculator {
    private double a, b, c;

    public MyCoolCalculator(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public double getPrice() {
        return a + b + c;
    }

    @Override
    public double getMinimalValue() {
        return Math.min(a, Math.min(b, c));
    }

    @Override
    public String getReport() {
        return String.format("MyCoolCalculator with a=%.1f, b=%.1f, c=%.1f", a, b, c);
    }
}