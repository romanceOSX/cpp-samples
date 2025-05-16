#include <iostream>
#include <algorithm>
#include <pthread.h>
#include <vector>
#include <type_traits>

template <typename T>
void print_container(T& cont) {
    std::cout << "Printing container..." << std::endl;
    for (auto& e: cont) {
        std::cout << e << std::endl;
    }
}

using Container_T = std::vector<int>;
Container_T v{10, 6, 5, 4, 3, 3, 6};

void _count_test() {
    auto c = std::count(std::begin(v), std::end(v), 2);
    std::cout << "There where " << c << " instances of" << std::endl;
}

template <typename T>
void sort_container(T& cont) {
    for (size_t i = 0; i < std::size(cont); i++) {

    for (auto it = std::begin(cont); it != std::end(cont); it++) {
        auto next = std::next(it);
        if (next == std::end(cont)) {
            break;
        }
        if (*it < *next) {
            std::iter_swap(it, next);
        }
    }

    }
}

template <typename T>
void reverse_container(T& c) {
}

void _copy_test() {
    std::vector v1{1, 2, 3, 4, 5};
    std::vector v2{9, 9, 8, 8, 7, 7};

    /*
     * We have to use a back inserter adaptor because std::copy just tries to advance
     * the iterator without caring if it can even hold the new value
     */
    std::copy(std::begin(v2), std::end(v2), std::back_inserter(v1));
    print_container(v1);
}

void _test_container_sort() {
    print_container(v);
    sort_container(v);
    print_container(v);
}

int main (int argc, char *argv[]) {
    //_count_test();
    //_test_container_sort();
    _copy_test();
    return 0;
}

