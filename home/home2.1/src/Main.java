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

    public void clear() {
        stats.clear();
        saveToFile();
        System.out.println("The history was deleted");
    }

    public void deleteUser(String name) {
        stats.remove(name);
        saveToFile();
        System.out.println("Statistics was deleted for " + name);
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

public class Main {
    public static void main(String[] args) {
        if (args.length != 1 && args.length != 2) {
            System.err.println("Usage: java Main <name> [delete]");
            System.exit(1);
        }

        String name = args[0];
        String databasePath = "statistics.txt";

        StatisticsDatabase database = new StatisticsDatabase(databasePath);
        database.load();

        if (name.equals("bread")) {
            database.clear();
        } else if (args.length == 2 && args[1].equals("delete")) {
            database.deleteUser(name);
        } else {
            int count = database.incrementUserAndGetCount(name);
            if (count == 1) {
                System.out.println("Welcome, " + name + "!");
            } else {
                System.out.println("Hello again(x=" + count + "), " + name);
            }
        }
    }
}
