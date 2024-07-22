public class Main {
    public static void main(String[] args) {
        PricePresenter<Integer> presenter1 = new PricePresenter<>(2);
        PricePresenter<Double> presenter2 = new PricePresenter<>(1.5);

        Milk milk = new Milk();
        Cookies cookies = new Cookies();
        Pineapple pineapple = new Pineapple();

        presenter1.printTotalPrice(milk, cookies);
        presenter2.printTotalPrice(pineapple, milk);
        presenter1.printTotalPrice(cookies, pineapple);
    }
}
