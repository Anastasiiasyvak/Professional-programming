import java.io.*;
import java.util.*;

class StatisticsDatabase {
    private Map<String, Integer> stats;
    private String filePath;

    public StatisticsDatabase(String filePath) {
        this.filePath = filePath;
        this.stats = new HashMap<>();
    }

    public void load() {
        try (Scanner scanner = new Scanner(new File(filePath))) {
            while (scanner.hasNext()) {
                String name = scanner.next();
                int count = scanner.nextInt();
                stats.put(name, count);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void save() {
        try (PrintWriter writer = new PrintWriter(filePath)) {
            for (Map.Entry<String, Integer> entry : stats.entrySet()) {
                writer.println(entry.getKey() + " " + entry.getValue());
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public String clear() {
        stats.clear();
        saveToFile();
        return "The history was deleted";
    }

    public String deleteUser(String name) {
        stats.remove(name);
        saveToFile();
        return "Statistics was deleted for " + name;
    }

    public int incrementUserAndGetCount(String name) {
        int count = stats.getOrDefault(name, 0);
        count++;
        stats.put(name, count);
        saveToFile();
        return count;
    }

    private void saveToFile() {
        try (PrintWriter writer = new PrintWriter(new FileWriter(filePath))) {
            for (Map.Entry<String, Integer> entry : stats.entrySet()) {
                writer.println(entry.getKey() + " " + entry.getValue());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
