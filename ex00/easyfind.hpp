#include <algorithm>
#include <stdexcept>

template <typename T>
concept Iterable = requires(T x) {
    { x.begin() } -> std::same_as<typename T::iterator>;
    { x.end() } -> std::same_as<typename T::iterator>;
};

template <Iterable T>
typename T::value_type easyfind(T& haystack, int needle) {
    auto it = std::find(haystack.begin(), haystack.end(), needle);
    if (it == haystack.end()) {
        throw std::runtime_error("Element not found");
    }
    return *it;
}
