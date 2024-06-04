public class Main {
    public static void main(String[] args) {
        testMegaDataInitialization();
        testMegaDataReset();
        testMegaDataPoolAcquireRelease();
        testMegaDataPoolExhaustion();
        System.out.println("All tests passed.");
    }

    private static void testMegaDataInitialization() {
        MegaData data = new MegaData();
        for (float val : data.smallArray) {
            assert val == 42.0f;
        }
        for (double val : data.bigArray) {
            assert val == 42.0;
        }
        System.out.println("testMegaDataInitialization passed.");
    }

    private static void testMegaDataReset() {
        MegaData data = new MegaData();
        data.smallArray[0] = 0.0f;
        data.bigArray[0] = 0.0;
        data.reset();
        assert data.smallArray[0] == 42.0f;
        assert data.bigArray[0] == 42.0;
        System.out.println("testMegaDataReset passed.");
    }

    private static void testMegaDataPoolAcquireRelease() {
        MegaDataPool pool = new MegaDataPool(10);
        assert pool.size() == 10;
        assert pool.usedSize() == 0;

        MegaData data1 = pool.acquire();
        assert data1 != null;
        assert pool.usedSize() == 1;

        pool.release(data1);
        assert pool.usedSize() == 0;
        System.out.println("testMegaDataPoolAcquireRelease passed.");
    }

    private static void testMegaDataPoolExhaustion() {
        MegaDataPool pool = new MegaDataPool(2);
        MegaData data1 = pool.acquire();
        MegaData data2 = pool.acquire();
        MegaData data3 = pool.acquire();
        assert data1 != null;
        assert data2 != null;
        assert data3 == null; 
        System.out.println("testMegaDataPoolExhaustion passed.");
    }
}
