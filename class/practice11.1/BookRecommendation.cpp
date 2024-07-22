#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <print>

int getRandomIndex(int max) {
    return rand() % max;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<std::string> books = {
        "The Topographer’s Clown",
        "The Chamber of Beaver",
        "The Ironer of Kanban",
        "The Piglet of Tire",
        "The Border of the Unix",
        "The Half-Time Convince",
        "The Earthly Pillows",
        "The Censorship of the Ping",
        "The True Powers",
        "The Overturn of the Ling"
    };

    std::vector<std::string> remainingBooks = books;

    std::string userResponse;

    while (!remainingBooks.empty()) {
        int index = getRandomIndex(remainingBooks.size());
        std::string book = remainingBooks[index];

        std::println("How about this book: {}?", book);
        std::println("Do you like it? (yes/no): ");
        std::cin >> userResponse;

        if (userResponse == "yes") {
            std::println("Great! Enjoy your book.");
            return 0;
        } else {
            remainingBooks.erase(remainingBooks.begin() + index);
        }
    }

    std::println("Adios amigo!");
    return 1;
}
