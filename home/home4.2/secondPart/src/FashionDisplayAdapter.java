public class FashionDisplayAdapter implements ModernFashionDisplay {
    private LegacyFashionDescription legacyFashionDescription;

    public FashionDisplayAdapter(LegacyFashionDescription legacyFashionDescription) {
        this.legacyFashionDescription = legacyFashionDescription;
    }

    @Override
    public void displayDescription(String description) {
        legacyFashionDescription.showDescription(description);
    }

    @Override
    public void displayImage(String imageUrl) {
        System.out.println("Fashion image: " + imageUrl);
    }
}