import java.util.List;

public class Pizza {
    private List<Ingredient> ingredients;

    public Pizza(List<Ingredient> ingredients) {
        this.ingredients = ingredients;
    }

    public void showIngredients() {
        for (Ingredient ingredient : ingredients) {
            System.out.println(ingredient.getName() + " - $" + ingredient.getCost());
        }
    }

    public double getCost() {
        double total = 0;
        for (Ingredient ingredient : ingredients) {
            total += ingredient.getCost();
        }
        return total;
    }
}
