#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

void loadStatistics(std::unordered_map<std::string, int>& stats) {
    std::ifstream infile("statistics.txt");
    std::string name;
    int count;
    while (infile >> name >> count) {
        stats[name] = count;
    }
}

void saveStatistics(const std::unordered_map<std::string, int>& stats) {
    std::ofstream outfile("statistics.txt");
    for (const auto& entry : stats) {
        outfile << entry.first << " " << entry.second << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: " << argv[0] << " <name> [delete]" << std::endl;
        return 1;
    }

    std::string name = argv[1];

    if (argc == 3 && std::string(argv[2]) != "delete") {
        std::cerr << "Usage: " << argv[0] << " <name> [delete]" << std::endl;
        return 1;
    }

    if (name == "bread") {
        std::ofstream outfile("statistics.txt", std::ofstream::trunc);
        std::cout << "The history was deleted" << std::endl;
        return 0;
    }

    std::unordered_map<std::string, int> stats;
    loadStatistics(stats);

    if (argc == 3 && std::string(argv[2]) == "delete") {
        stats.erase(name);
        std::cout << "Statistics was deleted for " << name << std::endl;
    } else {
        int& count = stats[name];
        count++;
        if (count == 1) {
            std::cout << "Welcome, " << name << "!" << std::endl;
        } else {
            std::cout << "Hello again(x=" << count << "), " << name << std::endl;
        }
    }

    saveStatistics(stats);
    return 0;
}
