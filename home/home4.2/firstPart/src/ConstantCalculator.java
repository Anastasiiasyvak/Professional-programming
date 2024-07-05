public class ConstantCalculator extends BaseMegaCalculator {
    @Override
    public double getPrice() {
        return 42;
    }

    @Override
    public double getMinimalValue() {
        return 0;
    }

    @Override
    public String getReport() {
        return "ConstantCalculator with a constant value";
    }
}