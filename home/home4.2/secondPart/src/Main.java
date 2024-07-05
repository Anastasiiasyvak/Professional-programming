public class Main {
    public static void main(String[] args) {
        ModernFashionDisplay display = new FashionDisplayAdapter(new LegacyFashionDescription());
        display.displayDescription("Elegant evening gown with sequins.");
        display.displayImage("https://ru.pinterest.com/search/pins/?q=fashion&rs=typed");
    }
}