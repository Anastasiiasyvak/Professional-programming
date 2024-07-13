import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] favoriteWords = new String[5];

        System.out.println("Enter your 5 favorite words:");
        for (int i = 0; i < 5; i++) {
            favoriteWords[i] = scanner.nextLine();
        }

        ExecutorService executorService = Executors.newFixedThreadPool(5);
        for (String word : favoriteWords) {
            executorService.execute(new WordPrinter(word));
        }

        executorService.shutdown();
        try {
            executorService.awaitTermination(1, TimeUnit.MINUTES);
        } catch (InterruptedException e) {
            executorService.shutdownNow();
        }

        System.out.println("All threads have finished.");
    }
}
