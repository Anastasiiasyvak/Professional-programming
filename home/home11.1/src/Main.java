import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        System.out.print("Enter your name: ");
        String name = scanner.nextLine();

        List<String> books = new ArrayList<>();
        books.add("The Topographer’s Clown");
        books.add("The Chamber of Beaver");
        books.add("The Ironer of Kanban");
        books.add("The Piglet of Tire");
        books.add("The Border of the Unix");
        books.add("The Half-Time Convince");
        books.add("The Earthly Pillows");
        books.add("The Censorship of the Ping");
        books.add("The True Powers");
        books.add("The Overturn of the Ling");

        List<String> remainingBooks = new ArrayList<>(books);

        while (!remainingBooks.isEmpty()) {
            int index = random.nextInt(remainingBooks.size());
            String book = remainingBooks.get(index);

            System.out.println("How about this book: " + book + "?");
            System.out.print("Do you like it? (yes/no): ");
            String userResponse = scanner.nextLine();

            if (userResponse.equalsIgnoreCase("yes")) {
                System.out.println("Great! Enjoy your book.");
                return;
            } else {
                remainingBooks.remove(index);
            }
        }

        System.out.println("Au revoir, " + name + "!");
    }
}
