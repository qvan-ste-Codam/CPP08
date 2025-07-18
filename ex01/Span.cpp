#include "Span.hpp"

#include <algorithm>
#include <cmath>
#include <numeric>
#include <stdexcept>

Span::Span(unsigned int n) : size{n} {}

Span::Span(const Span& other) : items{other.items}, size{other.size} {}

unsigned int Span::shortestSpan() const {
    if (items.size() < 2) {
        throw std::runtime_error("Not enough elements to calculate span");
    }
    std::vector<int> sortedItems = items;
    std::sort(sortedItems.begin(), sortedItems.end());
    std::vector<int> diff(sortedItems.size());
    std::adjacent_difference(sortedItems.begin(), sortedItems.end(),
                             diff.begin());
    return *std::min_element(diff.begin() + 1, diff.end());
}

unsigned int Span::longestSpan() const {
    if (items.size() < 2) {
        throw std::runtime_error("Not enough elements to calculate span");
    }
    int smallest = *std::min_element(items.begin(), items.end());
    int largest = *std::max_element(items.begin(), items.end());
    return static_cast<unsigned int>(std::abs(
        static_cast<long long>(largest) - static_cast<long long>(smallest)));
}

void Span::addNumber(const int num) {
    if (items.size() == size) {
        throw std::runtime_error("Vector is already full");
    }
    items.push_back(num);
};

Span& ::Span::operator=(const Span & other) {
    if (this != &other) {
        items = other.items;
        size = other.size;
    }
    return *this;
}
