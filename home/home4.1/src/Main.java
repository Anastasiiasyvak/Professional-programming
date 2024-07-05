import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    private static Map<String, Double> ingredients = new HashMap<>();

    public static void main(String[] args) {
        loadIngredients();

        Scanner scanner = new Scanner(System.in);
        System.out.println("Do you want to choose a classic pizza or compose a custom one? (classic/custom)");
        String choice = scanner.nextLine();

        PizzaBuilder builder = new PizzaBuilder();

        if (choice.equalsIgnoreCase("classic")) {
            System.out.println("Choose a classic pizza:");
            System.out.println("1. Margherita - tomatoes, basil, cheese");
            System.out.println("2. Pepperoni - tomatoes, cheese, pepperoni");
            System.out.println("3. Vegetarian - tomatoes, basil, cheese, onion, olives, mushrooms, pepper");

            int classicChoice = scanner.nextInt();
            scanner.nextLine();

            switch (classicChoice) {
                case 1:
                    builder.addIngredient(new Ingredient("tomatoes", ingredients.get("tomatoes")))
                            .addIngredient(new Ingredient("basil", ingredients.get("basil")))
                            .addIngredient(new Ingredient("cheese", ingredients.get("cheese")));
                    break;
                case 2:
                    builder.addIngredient(new Ingredient("tomatoes", ingredients.get("tomatoes")))
                            .addIngredient(new Ingredient("cheese", ingredients.get("cheese")))
                            .addIngredient(new Ingredient("pepperoni", ingredients.get("pepperoni")));
                    break;
                case 3:
                    builder.addIngredient(new Ingredient("tomatoes", ingredients.get("tomatoes")))
                            .addIngredient(new Ingredient("basil", ingredients.get("basil")))
                            .addIngredient(new Ingredient("cheese", ingredients.get("cheese")))
                            .addIngredient(new Ingredient("onion", ingredients.get("onion")))
                            .addIngredient(new Ingredient("olives", ingredients.get("olives")))
                            .addIngredient(new Ingredient("mushrooms", ingredients.get("mushrooms")))
                            .addIngredient(new Ingredient("pepper", ingredients.get("pepper")));
                    break;
                default:
                    System.out.println("Invalid choice!");
                    return;
            }
        } else {
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

        Pizza pizza = builder.build();
        System.out.println("Your pizza contains:");
        pizza.showIngredients();
        System.out.println("Total cost: $" + pizza.getCost());
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
