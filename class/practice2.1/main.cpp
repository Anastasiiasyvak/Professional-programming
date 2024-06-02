#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

namespace {
    constexpr char databasePath[] = "statistics.txt";
}

class StatisticsDatabase {
private:
    std::unordered_map<std::string, int> stats;
    std::string filePath;

public:
    StatisticsDatabase(const std::string& filePath) : filePath(filePath) {}

    void load() {
        std::ifstream infile(filePath);
        std::string name;
        int count;
        while (infile >> name >> count) {
            stats[name] = count;
        }
    }

    void save() const {
        std::ofstream outfile(filePath);
        for (const auto& entry : stats) {
            outfile << entry.first << " " << entry.second << std::endl;
        }
    }

    void clear() {
        stats.clear();
        saveToFile();
        std::cout << "The history was deleted" << std::endl;
    }

    void deleteUser(const std::string& name) {
        stats.erase(name);
        saveToFile();
        std::cout << "Statistics was deleted for " << name << std::endl;
    }

    int incrementUserAndGetCount(const std::string& name) {
        int& count = stats[name];
        count++;
        saveToFile();
        return count;
    }

private:
    void saveToFile() const {
        std::ofstream outfile(filePath, std::ofstream::trunc);
        for (const auto& entry : stats) {
            outfile << entry.first << " " << entry.second << std::endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2 && argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <name> [delete]" << std::endl;
        return 1;
    }

    std::string name = argv[1];

    StatisticsDatabase database(databasePath);
    database.load();

    if (name == "bread") {
        database.clear();
    } else if (argc == 3 && std::string(argv[2]) == "delete") {
        database.deleteUser(name);
    } else {
        int count = database.incrementUserAndGetCount(name);
        if (count == 1) {
            std::cout << "Welcome, " << name << "!" << std::endl;
        } else {
            std::cout << "Hello again(x=" << count << "), " << name << std::endl;
        }
    }

    return 0;
}
