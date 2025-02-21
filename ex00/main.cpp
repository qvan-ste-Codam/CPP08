#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"
int main(void) {
    std::vector<int> vecInt = {1, 2, 3, 4, 5};
    std::cout << "Testing std::vector<int>:" << std::endl;
    std::cout << easyfind<std::vector<int>>(vecInt, 5) << std::endl;
    try {
        std::cout << easyfind<std::vector<int>>(vecInt, -1) << std::endl;
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    std::list<int> listInt = {1, 2, 3, 4, 5};
    std::cout << "Testing std::list<int>:" << std::endl;
    std::cout << easyfind<std::list<int>>(listInt, 2) << std::endl;
    try {
        std::cout << easyfind<std::list<int>>(listInt, -1) << std::endl;
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
