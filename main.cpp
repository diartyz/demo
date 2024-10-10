#include <array>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <optional>
#include <stdexcept>

#include "fmt/format.h"

double devideNumbers(double numerator, double denominator)
{
    if (denominator == 0) {
        throw std::invalid_argument{"Denominator cannot be zero"};
    }
    return numerator / denominator;
}

int main()
{
    try {
        std::cout << devideNumbers(2.5, 0.5) << std::endl;
        std::cout << devideNumbers(2.5, 0) << std::endl;
    } catch (const std::invalid_argument& exception) {
        std::cout << fmt::format("Exception caught: {}", exception.what()) << std::endl;
    }

    return 0;
}
