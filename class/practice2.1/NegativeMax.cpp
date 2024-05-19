#include <ranges>
#include <print>
#include <algorithm>
#include <iostream>

int main()
{
    std::println("Enter the list of numbers separated by comma:");
    std::string inputString;
    std::getline(std::cin, inputString);

    constexpr std::string_view delimiter(",");
    auto filteredValues = std::views::split(inputString, delimiter)
        | std::ranges::to<std::vector<std::string>>()
        | std::views::filter([](const auto& str) { try { return std::stod(str) < 0; } catch (const std::exception& e) { return false; } })
        | std::ranges::views::transform([](const auto& str) { return std::stod(str); })
        | std::ranges::to<std::vector>();

    if (filteredValues.empty()) {
        std::println("No negative values in the list or incorrect input format");
    }
    else {
        std::println("Result is {}", std::ranges::max(filteredValues));
    }
}

