#include <iostream>
#include <algorithm>
#include <ranges>
#include <string>
#include <vector>

// -->  https://hannes.hauswedell.net/post/2019/11/30/range_intro/
namespace ranges = std::ranges;
namespace views = std::views;
using std::vector;
using std::string;

/* constrained generic function */
template <ranges::range T>
void print_collection(T& r) {
    std::cout << "{ ";
    ranges::for_each(r, [](auto& e) {
        std::cout << e << " ";
    });
    std::cout << "}" << std::endl;
}

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
     * vector
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

void test_ranges_str() {
    std::string s1{"This is an abcdefg"};
    print_collection(s1);
    auto r = s1
        | views::filter([](auto& c) {
            return c != 'a';
        });
    ranges::sort(s1);
    print_collection(s1);
}

void test_transforms() {
    vector<int> vec{1, 2, 3, 4, 4, 3, 2, 1};
    auto c = vec
        /* TODO: we have to return something forcefully?? why?? */
        | views::transform([](auto& e) { return e * 100; });

    print_collection(vec);

    auto replay = views::repeat("uid", 12);
    print_collection(replay);

    vector<string> string_vector{"This", "String", "Usted"};
    auto sv = string_vector | views::join;
    print_collection(string_vector);

    auto gen_view = views::repeat(1, 10) | views::take(4);
    print_collection(gen_view);
}

void test_mixing_views() {
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{1, 2, 3, 4, 5};
}

int main (int argc, char *argv[]) {
    test_transforms();
    //test_ranges_str();
    //test_ranges();
    return 0;
}

