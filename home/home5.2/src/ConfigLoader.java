import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class ConfigLoader {
    private static ConfigLoader instance;
    private final Map<Character, String[]> config = new HashMap<>();

    private ConfigLoader(String configFile) {
        loadConfig(configFile);
    }

    public static synchronized ConfigLoader getInstance(String configFile) {
        if (instance == null) {
            instance = new ConfigLoader(configFile);
        }
        return instance;
    }

    private boolean loadConfig(String configFile) {
        try (BufferedReader reader = new BufferedReader(new FileReader(configFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(" ");
                if (parts.length != 3) {
                    System.err.println("Invalid config line: " + line);
                    continue;
                }
                String range = parts[0];
                String preWord = parts[1];
                String postWord = parts[2];

                for (char c = range.charAt(0); c <= range.charAt(2); c++) {
                    config.put(c, new String[]{preWord, postWord});
                }
            }
            return true;
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }

    public String[] getConfig(char firstChar) {
        return config.getOrDefault(firstChar, new String[]{"", ""});
    }
}
