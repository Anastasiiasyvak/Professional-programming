#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Pixel {
    int r, g, b;
};

bool isValidPixel(const Pixel &pixel) {
    return (pixel.r >= 0 && pixel.r <= 255) && (pixel.g >= 0 && pixel.g <= 255) && (pixel.b >= 0 && pixel.b <= 255);
}

bool loadPixels(const string &filename, vector<vector<Pixel>> &pixels, string &errorMessage) {
    ifstream file(filename);
    if (!file.is_open()) {
        errorMessage = "Error: Could not open file " + filename;
        return false;
    }

    string line;
    int lineCount = 0;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        vector<Pixel> row;
        string pixelData;
        while (getline(ss, pixelData, ' ')) {
            Pixel pixel;
            replace(pixelData.begin(), pixelData.end(), ',', ' ');
            stringstream pixelStream(pixelData);
            if (!(pixelStream >> pixel.r >> pixel.g >> pixel.b) || !isValidPixel(pixel)) {
                errorMessage = "Invalid pixel data: " + pixelData;
                return false;
            }
            row.push_back(pixel);
        }
        if (row.size() != 16) {
            errorMessage = "Invalid data format: Each line must contain exactly 16 pixels.";
            return false;
        }
        pixels.push_back(row);
        lineCount++;
    }

    if (lineCount != 16) {
        errorMessage = "Invalid data format: File must contain exactly 16 lines.";
        return false;
    }

    return true;
}

void savePixels(const string &filename, const vector<vector<Pixel>> &pixels) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    for (const auto &row : pixels) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i].r << "," << row[i].g << "," << row[i].b;
            if (i < row.size() - 1) file << " ";
        }
        file << endl;
    }
}

void saveError(const string &filename, const string &errorMessage) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }
    file << errorMessage << endl;
}

void applyFavoriteColor(vector<vector<Pixel>> &pixels, const Pixel &favoriteColor) {
    for (size_t y = 0; y < 16; ++y) {
        for (size_t x = 0; x < 16; ++x) {
            if (pixels[y][x].r == favoriteColor.r && pixels[y][x].g == favoriteColor.g && pixels[y][x].b == favoriteColor.b) {
                if (x > 0) pixels[y][x - 1] = favoriteColor;
                if (y > 0) pixels[y - 1][x] = favoriteColor;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <input file> <favorite color> <output file>" << endl;
        cerr << "Favorite color format: R,G,B (e.g., 255,180,245)" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string favoriteColorStr = argv[2];
    string outputFile = argv[3];

    Pixel favoriteColor;
    replace(favoriteColorStr.begin(), favoriteColorStr.end(), ',', ' ');
    stringstream colorStream(favoriteColorStr);
    if (!(colorStream >> favoriteColor.r >> favoriteColor.g >> favoriteColor.b) || !isValidPixel(favoriteColor)) {
        cerr << "Error: Invalid favorite color format." << endl;
        return 1;
    }

    vector<vector<Pixel>> pixels;
    string errorMessage;
    if (!loadPixels(inputFile, pixels, errorMessage)) {
        cerr << errorMessage << endl;
        saveError(outputFile, errorMessage);
        return 1;
    }

    applyFavoriteColor(pixels, favoriteColor);
    savePixels(outputFile, pixels);

    cout << "Processing completed successfully." << endl;
    return 0;
}
