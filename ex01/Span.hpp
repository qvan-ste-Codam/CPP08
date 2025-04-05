#ifndef SPAN_HPP
#define SPAN_HPP
#include <stdexcept>
#include <vector>

class Span {
   public:
    Span() = delete;
    Span(unsigned int size);
    Span(const Span &other);
    ~Span() = default;
    Span &operator=(const Span &other);

    void addNumber(const int num);
    template <typename Range>
        requires std::same_as<typename Range::value_type, int>
    void addRange(const Range &ilist) {
        if (ilist.size() + items.size() > size) {
            throw std::runtime_error("Can't fit range into vector");
        }
        items.insert(items.end(), ilist.begin(), ilist.end());
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

   private:
    std::vector<int> items;
    unsigned int size;
};

#endif
