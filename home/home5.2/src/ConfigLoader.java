import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class ConfigLoader {
    private static ConfigLoader instance;
    private final Map<Character, String[]> config = new HashMap<>();

    private ConfigLoader() {
        loadConfig();
    }

    public static synchronized ConfigLoader getInstance() {
        if (instance == null) {
            instance = new ConfigLoader();
        }
        return instance;
    }

    private void loadConfig() {
        try (BufferedReader reader = new BufferedReader(new FileReader("config.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(" ");
                String range = parts[0];
                String preWord = parts[1];
                String postWord = parts[2];

                for (char c = range.charAt(0); c <= range.charAt(2); c++) {
                    config.put(c, new String[]{preWord, postWord});
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String[] getConfig(char firstChar) {
        return config.getOrDefault(firstChar, new String[]{"", ""});
    }
}
