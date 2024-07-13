import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Consumer;

public class MessageDispatcher {
    private Map<Integer, Consumer<GreenMessage>> greenSubscribers = new ConcurrentHashMap<>();
    private Map<Integer, Consumer<BlueMessage>> blueSubscribers = new ConcurrentHashMap<>();
    private Map<Integer, Consumer<OrangeMessage>> orangeSubscribers = new ConcurrentHashMap<>();
    private AtomicInteger idCounter = new AtomicInteger(0);

    private BlockingQueue<Object> messageQueue = new LinkedBlockingQueue<>();
    private ExecutorService executorService = Executors.newFixedThreadPool(4);
    private volatile boolean running = true;

    public MessageDispatcher() {
        for (int i = 0; i < 4; i++) {
            executorService.submit(this::processMessages);
        }
    }

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
        messageQueue.add(message);
    }

    public void publishBlue(BlueMessage message) {
        messageQueue.add(message);
    }

    public void publishOrange(OrangeMessage message) {
        messageQueue.add(message);
    }

    private void processMessages() {
        while (running) {
            try {
                Object message = messageQueue.take();
                if (message instanceof GreenMessage) {
                    greenSubscribers.values().forEach(subscriber -> subscriber.accept((GreenMessage) message));
                } else if (message instanceof BlueMessage) {
                    blueSubscribers.values().forEach(subscriber -> subscriber.accept((BlueMessage) message));
                } else if (message instanceof OrangeMessage) {
                    orangeSubscribers.values().forEach(subscriber -> subscriber.accept((OrangeMessage) message));
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }

    public void stop() {
        running = false;
        executorService.shutdown();
        try {
            if (!executorService.awaitTermination(60, TimeUnit.SECONDS)) {
                executorService.shutdownNow();
            }
        } catch (InterruptedException e) {
            executorService.shutdownNow();
            Thread.currentThread().interrupt();
        }
    }
}
