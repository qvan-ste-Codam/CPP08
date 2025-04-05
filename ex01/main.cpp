#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>

#include "Span.hpp"

void testLargeRange() {
    std::ofstream file("output.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file";
        exit(1);
    }
    Span sp4 = Span(42000);
    std::vector<int> randomNumbers(42000);
    std::random_device randomD;
    std::mt19937 generator(randomD());
    std::uniform_int_distribution<> distrib(INT32_MIN, INT32_MAX);
    std::generate(randomNumbers.begin(), randomNumbers.end(),
                  [&file, &distrib, &generator]() {
                      int num = distrib(generator);
                      file << num << '\n';
                      return num;
                  });
    std::cout << "MIN: "
              << *std::min_element(randomNumbers.begin(), randomNumbers.end())
              << " MAX: "
              << *std::max_element(randomNumbers.begin(), randomNumbers.end())
              << std::endl;
    sp4.addRange(randomNumbers);
    std::cout << sp4.shortestSpan() << std::endl;
    std::cout << sp4.longestSpan() << std::endl;
    file.close();
}

int main() {
    // Test normal inputs
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Expected: 2 Got: " << sp.shortestSpan() << std::endl;
    std::cout << "Expected: 14 Got: " << sp.longestSpan() << std::endl;
    Span sp2 = Span(5);
    sp2.addNumber(-123);
    sp2.addNumber(-123213);
    sp2.addNumber(0);
    sp2.addNumber(-123);
    sp2.addNumber(213);
    std::cout << "Expected: 0 Got: " << sp2.shortestSpan() << std::endl;
    std::cout << "Expected: 123426  Got: " << sp2.longestSpan() << std::endl;
    // Test range that is too small
    try {
        auto range = {1, 2, 3, 4, 5};
        sp2.addRange(range);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test valid range
    Span sp3 = Span(10);
    std::vector<int> range = {1, 2, 3, 4, 5, 6, 7, 8};
    sp3.addRange(range);
    std::cout << "Expected: 1 Got: " << sp3.shortestSpan() << std::endl;
    std::cout << "Expected 7 Got: " << sp3.longestSpan() << std::endl;

    testLargeRange();

    // Test invalid range
    std::vector<std::string> invalid({"hello", " world"});
    // sp4.addRange(invalid);
    return 0;
}
