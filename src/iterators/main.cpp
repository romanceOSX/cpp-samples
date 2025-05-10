#include <ranges>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void print_iterator_info() {
    using traits = std::iterator_traits<T>;
    std::cout << "Iterator class: " << typeid(typename traits::value_type).name() << std::endl;;
}

void _test_iterators() {
    using container = std::vector<int>;
    container v{1, 2, 3, 4, 5};
    print_iterator_info<container::iterator>();
}

template <typename T>
void print_container(T& v) {
    std::cout << "Printing container" << typeid(v).name() << std::endl;;
    for (auto e: v) {
        std::cout << e << std::endl;
    }
}

void _test_range_based_for_loop() {
    std::vector<int> v{1, 2, 3, 4, 5, 6};
    print_container(v);
    for (auto e: v) {
        e = 1;
    }
    print_container(v);
    for (auto&& e: v) {
        e = 1;
    }
    print_container(v);
}

int main (int argc, char *argv[]) {
    //_test_iterators();
    _test_range_based_for_loop();
    return 0;
}

