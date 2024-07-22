public class WordPrinter implements Runnable {
    private final String word;
    private final ConfigLoader configLoader;

    public WordPrinter(String word, ConfigLoader configLoader) {
        this.word = word;
        this.configLoader = configLoader;
    }

    @Override
    public void run() {
        String[] config = configLoader.getConfig(Character.toLowerCase(word.charAt(0)));
        String preWord = config[0];
        String postWord = config[1];

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        System.out.println(preWord + " " + word + " " + postWord);
    }
}
