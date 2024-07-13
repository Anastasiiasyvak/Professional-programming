import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class IngredientTest {
    public static void main(String[] args) {
        testIngredient();
        testPizzaBuilder();
        testPizza();
        System.out.println("All tests passed!");
    }

    static void testIngredient() {
        Ingredient ingredient = new Ingredient("tomatoes", 15.0);
        assert "tomatoes".equals(ingredient.getName());
        assert ingredient.getCost() == 15.0;
        System.out.println("testIngredient passed");
    }

    static void testPizzaBuilder() {
        PizzaBuilder builder = new PizzaBuilder();
        builder.addIngredient(new Ingredient("tomatoes", 15.0));
        builder.addIngredient(new Ingredient("cheese", 20.0));
        Pizza pizza = builder.build();
        assert pizza.getCost() == 35.0;
        System.out.println("testPizzaBuilder passed");
    }

    static void testPizza() {
        List<Ingredient> ingredients = Arrays.asList(
                new Ingredient("tomatoes", 15.0),
                new Ingredient("cheese", 20.0)
        );
        Pizza pizza = new Pizza(ingredients);
        assert pizza.getCost() == 35.0;
        System.out.println("testPizza passed");
    }
}
