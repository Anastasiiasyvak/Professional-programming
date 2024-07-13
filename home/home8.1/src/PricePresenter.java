public class PricePresenter<PRIORITY extends Number> {
    private final PRIORITY priority;

    public PricePresenter(PRIORITY priority) {
        this.priority = priority;
    }

    public <T extends Priceable, U extends Priceable> void printTotalPrice(T obj1, U obj2) {
        double totalPrice = priority.doubleValue() * obj1.getCoefficient() * obj1.getBasePrice()
                + obj2.getCoefficient() * obj2.getBasePrice();
        System.out.println("Total price: " + totalPrice);
    }
}
