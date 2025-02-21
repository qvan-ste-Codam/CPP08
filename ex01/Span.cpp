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
    return *std::min_element(diff.begin(), diff.end());
}

unsigned int Span::longestSpan() const {
    if (items.size() < 2) {
        throw std::runtime_error("Not enough elements to calculate span");
    }
    int smallest = *std::min_element(items.begin(), items.end());
    int largest = *std::max_element(items.begin(), items.end());
    return std::abs(largest - smallest);
}

void Span::addNumber(const int num) {
    if (items.size() == size) {
        throw std::runtime_error("Vector is already full");
    }
    items.push_back(num);
};

void Span::addRange(std::initializer_list<int> ilist) {
    if (ilist.size() + items.size() > size) {
        throw std::runtime_error("Can't fit range into vector");
    }
    items.insert(items.end(), ilist.begin(), ilist.end());
}
Span& ::Span::operator=(const Span & other) {
    if (this != &other) {
        items = other.items;
        size = other.size;
    }
    return *this;
}
