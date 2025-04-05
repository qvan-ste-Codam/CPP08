#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
template <typename T>
class MutantStack : public std::stack<T> {
   public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    MutantStack() = default;
    MutantStack(const MutantStack &other) : std::stack<T>(other) {};
    ~MutantStack() = default;
    MutantStack &operator=(const MutantStack &other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    };
    iterator begin() { return std::stack<T>::c.begin(); }

    iterator end() { return std::stack<T>::c.end(); }
};

#endif
