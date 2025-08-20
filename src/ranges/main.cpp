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
    /*
     * ranges
     */
    std::vector v{10, 11, 2, 2, 3, 1, 4, 5};
    print_collection(v);

    /* a vector is a range because it is compliant with the std::range concept */
    ranges::sort(v);
    print_collection(v);

    ranges::sort(ranges::views::reverse(v));
    print_collection(v);

    /* 
     * adaptors / views
     */
    std::vector v2{10, 23, 2, 1, 45, 5, 5};
    /* drop the first 3 then reverse the thing */
    auto v_adaptor = v2 | std::views::reverse | std::views::drop(3);
    std::cout << *v_adaptor.begin() << std::endl;
    print_collection(v_adaptor);
    print_collection(v2);

    /*
     *
     */
    std::vector c{1, 2, 4, 5, 2, 1, 10, 38, 2};
    print_collection(c);
    auto res = std::move(c)
        | std::views::drop(3)
        | std::views::reverse
        | std::views::filter([](auto& e) { return e < 10; })
        | std::ranges::to<std::vector>();
    print_collection(res);
}

int main (int argc, char *argv[]) {
    test_ranges();
    return 0;
}

