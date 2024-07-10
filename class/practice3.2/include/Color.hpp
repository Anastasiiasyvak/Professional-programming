#pragma once

class Color {
public:
    Color(int r, int g, int b) : red(r), green(g), blue(b) {}

    void generateMagicColor() {
        red = red / 2 - 1;
        green = green * 2 - 2;
    }

    int getRed() const { return red; }
    int getGreen() const { return green; }
    int getBlue() const { return blue; }

private:
    int red, green, blue;
};
