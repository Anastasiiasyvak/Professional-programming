import java.util.ArrayList;
import java.util.List;

public class MegaDataPool {
    private final List<MegaData> pool;
    private final List<MegaData> available;

    public MegaDataPool(int size) {
        pool = new ArrayList<>(size);
        available = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            MegaData data = new MegaData();
            pool.add(data);
            available.add(data);
        }
    }

    public synchronized MegaData acquire() {
        if (available.isEmpty()) {
            return null; 
        }
        return available.remove(available.size() - 1);
    }

    public synchronized void release(MegaData obj) {
        obj.reset();
        available.add(obj);
    }

    public int size() {
        return pool.size();
    }

    public int usedSize() {
        return pool.size() - available.size();
    }
}
