public class MegaData {
    private static final int SMALL_ARRAY_SIZE = 1024;
    private static final int BIG_ARRAY_SIZE = 1024 * 1024;

    public float[] smallArray;
    public double[] bigArray;

    public MegaData() {
        smallArray = new float[SMALL_ARRAY_SIZE];
        bigArray = new double[BIG_ARRAY_SIZE];
        reset();
    }

    public void reset() {
        for (int i = 0; i < SMALL_ARRAY_SIZE; i++) {
            smallArray[i] = 42.0f;
        }
        for (int i = 0; i < BIG_ARRAY_SIZE; i++) {
            bigArray[i] = 42.0;
        }
    }
}
