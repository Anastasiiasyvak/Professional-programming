#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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

    for (const auto& str : splitStrings) {
        try {
            double value = std::stod(str);
            if (value < 0) {
                filteredValues.push_back(value);
            }
        } catch (const std::exception&) {
        }
    }

    if (filteredValues.empty()) {
        std::cout << "No negative values in the list or incorrect input format" << std::endl;
    } else {
        auto maxElement = *std::max_element(filteredValues.begin(), filteredValues.end());
        std::cout << "Result is " << maxElement << std::endl;
    }

    return 0;
}
