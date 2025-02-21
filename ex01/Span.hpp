#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>

class Span {
   public:
    Span() = delete;
    Span(unsigned int size);
    Span(const Span &other);
    ~Span() = default;
    Span &operator=(const Span &other);

    void addNumber(const int num);
    void addRange(const std::initializer_list<int> ilist);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

   private:
    std::vector<int> items;
    unsigned int size;
};

#endif
