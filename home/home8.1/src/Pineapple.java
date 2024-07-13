public class Pineapple implements Priceable {
    @Override
    public double getCoefficient() {
        return 1.1;
    }

    @Override
    public double getBasePrice() {
        return 5.0;
    }
}
