#include <vector>
#include <iostream>
#include <map>
#include <ranges>

using StringMap = std::map<std::string, std::string>;

namespace ranges = std::ranges;
using std::vector;

template <ranges::range T>
T::value_type move_last(T& cont) {
    return *cont.end();
}

template <ranges::range T>
void print_container(T& cont) {
    ranges::for_each(cont, [](auto& e) { std::cout << e << std::endl;});
}

/*
 * std::move is just a cast to a an rvalue reference
 * If the consuming class has a move constructor, then the overload mechanism will
 * match the move constructor because of the rvalueness of the type
 * Once it is matched, the move constructor semantically allows you to 'steal' the
 * contents of an rvalue type
 * If nothing is done with that rvalue, then nothing happens
 *  TODO: It seems that if there is no move constructor then it falls back to copy constructor
 *        how does this work?
 */

void test_last_element() {
    vector<int> vint{1, 2, 3, 4, 5, 6};

    print_container(vint);
    move_last(vint);
    print_container(vint);
    std::move(*vint.end());
    print_container(vint);
}

void _map_test() {
    StringMap sm{{"Hello", "world"}};

    sm.insert({"a", "b"});

    for (auto& [k, v]: sm) {
        std::cout << k << " : " << v << std::endl;
    }
}

void _vector_test() {
    std::vector<int> vi = {1, 2, 3, 4, 5};   
    std::cout << vi.at(0) << std::endl;
}

int main (int argc, char *argv[]) {
    //_map_test();
    test_last_element();
    return 0;
}

