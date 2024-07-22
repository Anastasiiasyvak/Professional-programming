public class InverseCalculator {
    public double inverse(double x, double y, double z) {
        double product = x * y * z;
        double sum = x + y + z;

        if (product != 0) {
            return 1.0 / product;
        } else if (sum != 0) {
            return 1.0 / sum;
        } else {
            return x + (y + 1) * (z - 1);
        }
    }
}
