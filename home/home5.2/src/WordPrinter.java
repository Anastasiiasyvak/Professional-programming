public class WordPrinter implements Runnable {
    private final String word;

    public WordPrinter(String word) {
        this.word = word;
    }

    @Override
    public void run() {
        ConfigLoader configLoader = ConfigLoader.getInstance();
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
