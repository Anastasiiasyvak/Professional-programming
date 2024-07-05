public class LegacyCalculator {
    private double megaDelta;
    private double megaMultiplier;
    private static final double STRANGE_VAL1 = 6.0;
    private static final double STRANGE_VAL2 = 13.0;

    public LegacyCalculator(double inMegaDelta, double inMegaMultiplier) {
        this.megaDelta = inMegaDelta;
        this.megaMultiplier = inMegaMultiplier;
    }

    public double calculatePricePart1() {
        return STRANGE_VAL1 - megaDelta;
    }

    public double calculatePricePart2() {
        return STRANGE_VAL2 * megaMultiplier + 1 - megaDelta;
    }

    public double getOurTheMostAndMinimalValue() {
        return megaDelta * megaMultiplier;
    }

    public String getSomeDocumentRepresentation() {
        return String.format("The man %.2f who sold the %.2f world",
                STRANGE_VAL1 - megaDelta,
                megaMultiplier * STRANGE_VAL2);
    }
}