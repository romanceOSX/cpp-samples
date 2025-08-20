#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>

template <typename T>
void print_collection(T&& c) { 
    std::cout << "[ ";
    for (auto& e : c) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
}

// -->  https://hannes.hauswedell.net/post/2019/11/30/range_intro/

namespace ranges = std::ranges;

void test_ranges() {
    std::vector v{10, 11, 2, 2, 3, 1, 4, 5};
    print_collection(v);

    /* a vector is a range because it is compliant with the std::range concept */
    ranges::sort(v);
    print_collection(v);

    ranges::sort(ranges::views::reverse(v));
    print_collection(v);
}

int main (int argc, char *argv[]) {
    test_ranges();
    return 0;
}

