public class Main {
    public static void main(String[] args) {
        printResults(new MyCoolCalculator(6.0, 12.1, 3.2));
        printResults(new ConstantCalculator());
        printResults(new MegaAdapter(new LegacyCalculator(1.34, 5.4)));
    }

    private static void printResults(BaseMegaCalculator calculator) {
        System.out.printf("Current price: %.2f%n", calculator.getPrice());
        System.out.printf("Current minimal value: %.2f%n", calculator.getMinimalValue());
        System.out.printf("Current report: %s%n", calculator.getReport());
    }
}