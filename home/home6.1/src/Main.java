import java.util.Random;

public class Main {
    public static void main(String[] args) {
        MessageDispatcher dispatcher = new MessageDispatcher();

        int greenSubscriptionId = dispatcher.subscribeGreen(message ->
                System.out.println("GreenMessage received: " + message.getMessage() + ", counter: " + message.getCounter())
        );
        int blueSubscriptionId = dispatcher.subscribeBlue(message ->
                System.out.println("BlueMessage received: " + message.getValue1() + ", " + message.getValue2())
        );
        int orangeSubscriptionId = dispatcher.subscribeOrange(message ->
                System.out.println("OrangeMessage received: " + message.getMessage1() + ", " + message.getMessage2() +
                        ", " + message.getNumber() + ", " + message.getValue())
        );

        Thread thread1 = new Thread(() -> {
            Random random = new Random();
            for (int i = 0; i < 10; i++) {
                dispatcher.publishGreen(new GreenMessage("Hello from thread 1", i));
                dispatcher.publishBlue(new BlueMessage(i, i + 0.5));
                dispatcher.publishOrange(new OrangeMessage("Thread 1 says", "Hi there!", i, i + 0.1));
                try {
                    Thread.sleep(random.nextInt(1000));
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
        });

        Thread thread2 = new Thread(() -> {
            Random random = new Random();
            for (int i = 0; i < 10; i++) {
                dispatcher.publishGreen(new GreenMessage("Hello from thread 2", i));
                dispatcher.publishBlue(new BlueMessage(i, i + 0.5));
                dispatcher.publishOrange(new OrangeMessage("Thread 2 says", "Hi there!", i, i + 0.2));
                try {
                    Thread.sleep(random.nextInt(1000));
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
        });

        thread1.start();
        thread2.start();

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        dispatcher.unsubscribeGreen(greenSubscriptionId);
        dispatcher.unsubscribeBlue(blueSubscriptionId);
        dispatcher.unsubscribeOrange(orangeSubscriptionId);

        dispatcher.stop();
    }
}
