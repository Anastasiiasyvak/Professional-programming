#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <print>

struct Pixel {
    int r = 0;
    int g = 0;
    int b = 0;

    bool isValid() const {
        return (r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255);
    }

    friend std::istream& operator>>(std::istream& is, Pixel& pixel) {
        char comma1, comma2;
        return is >> pixel.r >> comma1 >> pixel.g >> comma2 >> pixel.b;
    }

    friend bool operator==(const Pixel& lhs, const Pixel& rhs) {
        return lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b;
    }
};

class Image {
public:
    bool initFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::println(stderr, "Error: Could not open file {}", filename);
            return false;
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;

            std::stringstream ss(line);
            std::vector<Pixel> row;
            row.reserve(16); 

            Pixel pixel;
            while (ss >> pixel) {
                if (!pixel.isValid()) {
                    std::println(stderr, "Invalid pixel data: {} {} {}.", pixel.r, pixel.g, pixel.b);
                    return false;
                }
                row.push_back(pixel);
            }

            if (row.size() != 16) {
                std::println(stderr, "Invalid data format: Each line must contain exactly 16 pixels.");
                return false;
            }
            pixels.push_back(row);
        }

        return pixels.size() == 16; // Ensure 16 lines
    }

    bool saveToFile(const std::string& outFile) const {
        std::ofstream file(outFile);
        if (!file.is_open()) {
            std::println(stderr, "Error: Could not open file {}", outFile);
            return false;
        }

        for (const auto& row : pixels) {
            for (const auto& pixel : row) {
                std::println(file, "{},{},{}", pixel.r, pixel.g, pixel.b);
            }
        }
        return true;
    }

    void applyFavoriteColor(const Pixel& favoriteColor) {
        for (size_t y = 0; y < pixels.size(); ++y) {
            for (size_t x = 0; x < pixels[y].size(); ++x) {
                if (pixels[y][x] == favoriteColor) {
                    if (x > 0) pixels[y][x - 1] = favoriteColor; 
                    if (y > 0) pixels[y - 1][x] = favoriteColor; 
                }
            }
        }
    }

private:
    std::vector<std::vector<Pixel>> pixels;
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::println(stderr, "Usage: {} <input file> <favorite color> <output file>", argv[0]);
        std::println(stderr, "Favorite color format: R,G,B (e.g., 255,180,245)");
        return 1;
    }

    std::string inputFile = argv[1];
    std::string favoriteColorStr = argv[2];
    std::string outputFile = argv[3];

    Pixel favoriteColor;
    std::replace(favoriteColorStr.begin(), favoriteColorStr.end(), ',', ' ');
    std::stringstream colorStream(favoriteColorStr);
    if (!(colorStream >> favoriteColor) || !favoriteColor.isValid()) {
        std::println(stderr, "Error: Invalid favorite color format.");
        return 1;
    }

    Image image;
    if (!image.initFromFile(inputFile)) {
        return 1; 
    }

    image.applyFavoriteColor(favoriteColor);
    if (!image.saveToFile(outputFile)) {
        return 1; 
    }

    std::println("Processing completed successfully.");
    return 0;
}

