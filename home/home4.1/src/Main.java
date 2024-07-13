import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    private static final Map<String, Double> ingredients = new HashMap<>();
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        loadIngredients();
        choosePizza();
    }

    private static void choosePizza() {
        System.out.println("Do you want to choose a classic pizza or compose a custom one? (classic/custom)");
        String choice = scanner.nextLine();

        PizzaBuilder builder = new PizzaBuilder();

        if (choice.equalsIgnoreCase("classic")) {
            handleClassicPizza(builder);
        } else {
            handleCustomPizza(builder);
        }

        Pizza pizza = builder.build();
        System.out.println("Your pizza contains:");
        pizza.showIngredients();
        System.out.println("Total cost: $" + pizza.getCost());
    }

    private static void handleClassicPizza(PizzaBuilder builder) {
        System.out.println("Choose a classic pizza:");
        System.out.println("1. Margherita - tomatoes, basil, cheese");
        System.out.println("2. Pepperoni - tomatoes, cheese, pepperoni");
        System.out.println("3. Vegetarian - tomatoes, basil, cheese, onion, olives, mushrooms, pepper");

        int classicChoice = scanner.nextInt();
        scanner.nextLine();

        switch (classicChoice) {
            case 1:
                addIngredientsToBuilder(builder, "tomatoes", "basil", "cheese");
                break;
            case 2:
                addIngredientsToBuilder(builder, "tomatoes", "cheese", "pepperoni");
                break;
            case 3:
                addIngredientsToBuilder(builder, "tomatoes", "basil", "cheese", "onion", "olives", "mushrooms", "pepper");
                break;
            default:
                System.out.println("Invalid choice!");
                return;
        }
    }

    private static void handleCustomPizza(PizzaBuilder builder) {
        while (true) {
            System.out.println("Available ingredients:");
            for (Map.Entry<String, Double> entry : ingredients.entrySet()) {
                System.out.println(entry.getKey() + " - $" + entry.getValue());
            }
            System.out.println("Enter an ingredient or type 'done' to finish: ");
            String ingredientName = scanner.nextLine();

            if (ingredientName.equalsIgnoreCase("done")) break;

            if (ingredients.containsKey(ingredientName)) {
                builder.addIngredient(new Ingredient(ingredientName, ingredients.get(ingredientName)));
            } else {
                System.out.println("Ingredient not found!");
            }
        }
    }

    private static void addIngredientsToBuilder(PizzaBuilder builder, String... ingredientNames) {
        for (String name : ingredientNames) {
            builder.addIngredient(new Ingredient(name, ingredients.get(name)));
        }
    }

    private static void loadIngredients() {
        ingredients.put("tomatoes", 15.0);
        ingredients.put("basil", 18.0);
        ingredients.put("cheese", 20.0);
        ingredients.put("mozzarella", 22.0);
        ingredients.put("onion", 8.0);
        ingredients.put("olives", 12.0);
        ingredients.put("ham", 25.0);
        ingredients.put("bacon", 27.0);
        ingredients.put("pepperoni", 25.0);
        ingredients.put("eggplant", 10.0);
        ingredients.put("sausages", 23.0);
        ingredients.put("mushrooms", 10.0);
        ingredients.put("pesto", 20.0);
        ingredients.put("pepper", 10.0);
        ingredients.put("anchovies", 28.0);
    }
}
