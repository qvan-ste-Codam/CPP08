#include <iostream>
#include <list>
#include <vector>

#include "MutantStack.hpp"

int main() {
    {
        std::cout << "Mutant stack <int>" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;

        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << "\nMutant stack end values" << std::endl;
        for (auto i : mstack) {
            std::cout << i << std::endl;
        }
        std::cout << "\nRealstack end values (printed in reverse)" << std::endl;
        std::stack<int> s(mstack);
        size_t size = s.size();
        for (size_t i = 0; i < size; i++) {
            std::cout << s.top() << std::endl;
            s.pop();
        }
    }
    {
        std::cout << "\nlist<int>" << std::endl;
        std::list<int> list;
        list.push_back(5);
        list.push_back(17);
        std::cout << list.back() << std::endl;
        list.pop_back();
        std::cout << list.size() << std::endl;
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        list.push_back(0);
        auto it = list.begin();
        auto ite = list.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    {
        std::cout << "\nMutant stack <string>" << std::endl;
        MutantStack<std::string> mstack;
        mstack.push("hello");
        mstack.push("world");
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push("A");
        mstack.push("B");
        mstack.push("C");
        mstack.push("D");
        auto it = mstack.begin();
        auto ite = mstack.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << "\nMutant stack end values" << std::endl;
        for (auto s : mstack) {
            std::cout << s << std::endl;
        }
        std::cout << "\nRealstack end values (printed in reverse)" << std::endl;
        std::stack<std::string> s(mstack);
        size_t size = s.size();
        for (size_t i = 0; i < size; i++) {
            std::cout << s.top() << std::endl;
            s.pop();
        }
    }
    {
        std::cout << "\nvector<string>" << std::endl;
        std::vector<std::string> vec;
        vec.push_back("hello");
        vec.push_back("world");
        std::cout << vec.back() << std::endl;
        vec.pop_back();
        std::cout << vec.size() << std::endl;
        vec.push_back("A");
        vec.push_back("B");
        vec.push_back("C");
        vec.push_back("D");
        auto it = vec.begin();
        auto ite = vec.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::vector<std::string> s(vec);
    }
}
