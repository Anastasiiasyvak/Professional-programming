import java.util.*;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Consumer;

public class MessageDispatcher {
    private Map<Integer, Consumer<GreenMessage>> greenSubscribers = new ConcurrentHashMap<>();
    private Map<Integer, Consumer<BlueMessage>> blueSubscribers = new ConcurrentHashMap<>();
    private Map<Integer, Consumer<OrangeMessage>> orangeSubscribers = new ConcurrentHashMap<>();
    private AtomicInteger idCounter = new AtomicInteger(0);

    public int subscribeGreen(Consumer<GreenMessage> subscriber) {
        int id = idCounter.incrementAndGet();
        greenSubscribers.put(id, subscriber);
        return id;
    }

    public int subscribeBlue(Consumer<BlueMessage> subscriber) {
        int id = idCounter.incrementAndGet();
        blueSubscribers.put(id, subscriber);
        return id;
    }

    public int subscribeOrange(Consumer<OrangeMessage> subscriber) {
        int id = idCounter.incrementAndGet();
        orangeSubscribers.put(id, subscriber);
        return id;
    }

    public void unsubscribeGreen(int id) {
        greenSubscribers.remove(id);
    }

    public void unsubscribeBlue(int id) {
        blueSubscribers.remove(id);
    }

    public void unsubscribeOrange(int id) {
        orangeSubscribers.remove(id);
    }

    public void publishGreen(GreenMessage message) {
        greenSubscribers.values().forEach(subscriber -> subscriber.accept(message));
    }

    public void publishBlue(BlueMessage message) {
        blueSubscribers.values().forEach(subscriber -> subscriber.accept(message));
    }

    public void publishOrange(OrangeMessage message) {
        orangeSubscribers.values().forEach(subscriber -> subscriber.accept(message));
    }
}
