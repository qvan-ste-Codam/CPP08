#include <iostream>

#include "Span.hpp"
int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    Span sp2 = Span(5);
    sp2.addNumber(-123);
    sp2.addNumber(-123213);
    sp2.addNumber(0);
    sp2.addNumber(-123);
    sp2.addNumber(213);
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    try {
        auto range = {1, 2, 3, 4, 5};
        sp2.addRange(range);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    Span sp3 = Span(10);
    sp3.addRange({1, 2, 3, 4, 5, 6, 7, 8});
    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;

    return 0;
}
