#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ranges>

int main()
{
    std::cout << "Enter the list of numbers separated by comma:" << std::endl;
    std::string inputString;
    std::getline(std::cin, inputString);

    std::vector<std::string> splitStrings;
    std::stringstream ss(inputString);
    std::string token;

    while (std::getline(ss, token, ',')) {
        splitStrings.push_back(token);
    }

    std::vector<double> filteredValues;

    auto filterNegative = [](const std::string& str) {
        try {
            return std::stod(str);
        } catch (const std::exception&) {
            return 0.0; // Ignore non-numeric strings
        }
    };

    for (const auto& str : splitStrings) {
        double value = filterNegative(str);
        if (value < 0) {
            filteredValues.push_back(value);
        }
    }

    if (filteredValues.empty()) {
        std::cout << "No negative values in the list or incorrect input format" << std::endl;
    } else {
        auto maxElement = *std::ranges::max_element(filteredValues);
        std::cout << "Result is " << maxElement << std::endl;
    }

    return 0;
}
