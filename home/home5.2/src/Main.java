import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Main {
    private static final String CONFIG_FILE = "/home/nastia/IdeaProjects/5.2rewrite/src/config.txt";

    public static void main(String[] args) {
        ConfigLoader configLoader = ConfigLoader.getInstance(CONFIG_FILE);

        Scanner scanner = new Scanner(System.in);
        String[] favoriteWords = new String[5];

        System.out.println("Enter your 5 favorite words:");
        for (int i = 0; i < 5; i++) {
            favoriteWords[i] = scanner.nextLine();
        }

        ExecutorService executorService = Executors.newFixedThreadPool(5);
        for (String word : favoriteWords) {
            executorService.execute(new WordPrinter(word, configLoader));
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
