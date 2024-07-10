import java.io.*;
import java.util.*;

public class FavoriteColorProgram {
    public static boolean isValidPixel(Pixel pixel) {
        return (pixel.getR() >= 0 && pixel.getR() <= 255) &&
                (pixel.getG() >= 0 && pixel.getG() <= 255) &&
                (pixel.getB() >= 0 && pixel.getB() <= 255);
    }

    public static boolean loadPixels(String filename, List<List<Pixel>> pixels, StringBuilder errorMessage) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            int lineCount = 0;
            while ((line = reader.readLine()) != null) {
                if (line.isEmpty()) continue;
                String[] pixelData = line.trim().split("\\s+");
                List<Pixel> row = new ArrayList<>();
                for (String pixelStr : pixelData) {
                    String[] rgb = pixelStr.split(",");
                    int r = Integer.parseInt(rgb[0]);
                    int g = Integer.parseInt(rgb[1]);
                    int b = Integer.parseInt(rgb[2]);
                    Pixel pixel = new Pixel(r, g, b);
                    if (!isValidPixel(pixel)) {
                        errorMessage.append("Invalid pixel data: ").append(pixelStr);
                        return false;
                    }
                    row.add(pixel);
                }
                if (row.size() != 16) {
                    errorMessage.append("Invalid data format: Each line must contain exactly 16 pixels.");
                    return false;
                }
                pixels.add(row);
                lineCount++;
            }
            if (lineCount != 16) {
                errorMessage.append("Invalid data format: File must contain exactly 16 lines.");
                return false;
            }
            return true;
        } catch (IOException | NumberFormatException e) {
            errorMessage.append("Error: ").append(e.getMessage());
            return false;
        }
    }

    public static void savePixels(String filename, List<List<Pixel>> pixels) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(filename))) {
            for (List<Pixel> row : pixels) {
                for (int i = 0; i < row.size(); i++) {
                    writer.print(row.get(i));
                    if (i < row.size() - 1) writer.print(" ");
                }
                writer.println();
            }
        } catch (IOException e) {
            System.err.println("Error: Could not write to file " + filename);
        }
    }

    public static void saveError(String filename, String errorMessage) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(filename))) {
            writer.println(errorMessage);
        } catch (IOException e) {
            System.err.println("Error: Could not write error message to file " + filename);
        }
    }

    public static void applyFavoriteColor(List<List<Pixel>> pixels, Pixel favoriteColor, Pixel unfavoriteColor) {
        for (int y = 0; y < 16; y++) {
            for (int x = 0; x < 16; x++) {
                Pixel currentPixel = pixels.get(y).get(x);
                if (currentPixel.equals(unfavoriteColor)) {
                    pixels.get(y).set(x, favoriteColor);
                }
            }
        }
    }

    public static void main(String[] args) {
        if (args.length != 4) {
            System.err.println("Usage: java FavoriteColorProgram <input file> <favorite color> <unfavorite color> <output file>");
            System.err.println("Favorite color format: R,G,B (e.g., 255,180,245)");
            return;
        }

        String inputFile = args[0];
        String favoriteColorStr = args[1];
        String unfavoriteColorStr = args[2];
        String outputFile = args[3];

        String[] favoriteRGB = favoriteColorStr.split(",");
        String[] unfavoriteRGB = unfavoriteColorStr.split(",");
        Pixel favoriteColor = new Pixel(Integer.parseInt(favoriteRGB[0]), Integer.parseInt(favoriteRGB[1]), Integer.parseInt(favoriteRGB[2]));
        Pixel unfavoriteColor = new Pixel(Integer.parseInt(unfavoriteRGB[0]), Integer.parseInt(unfavoriteRGB[1]), Integer.parseInt(unfavoriteRGB[2]));

        List<List<Pixel>> pixels = new ArrayList<>();
        StringBuilder errorMessage = new StringBuilder();

        if (!loadPixels(inputFile, pixels, errorMessage)) {
            System.err.println(errorMessage.toString());
            saveError(outputFile, errorMessage.toString());
            return;
        }

        applyFavoriteColor(pixels, favoriteColor, unfavoriteColor);
        savePixels(outputFile, pixels);

        System.out.println("Processing completed successfully.");
    }
}
