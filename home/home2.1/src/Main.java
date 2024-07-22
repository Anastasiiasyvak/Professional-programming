import java.io.*;

public class Main {
    private static final String DATABASE_PATH = "statistics.txt";
    private static final String CLEAR_COMMAND = "bread";
    private static final String DELETE_COMMAND = "delete";

    public static void main(String[] args) {
        if (args.length != 1 && args.length != 2) {
            System.err.println("Usage: java Main <name> [delete]");
            System.exit(1);
        }

        String name = args[0];
        StatisticsDatabase database = new StatisticsDatabase(DATABASE_PATH);
        database.load();

        if (name.equals(CLEAR_COMMAND)) {
            System.out.println(database.clear());
        } else if (args.length == 2 && args[1].equals(DELETE_COMMAND)) {
            System.out.println(database.deleteUser(name));
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
