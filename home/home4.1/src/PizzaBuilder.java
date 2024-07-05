import java.util.ArrayList;
import java.util.List;

public class PizzaBuilder {
    private List<Ingredient> ingredients;

    public PizzaBuilder() {
        this.ingredients = new ArrayList<>();
    }

    public PizzaBuilder addIngredient(Ingredient ingredient) {
        ingredients.add(ingredient);
        return this;
    }

    public Pizza build() {
        return new Pizza(ingredients);
    }
}
