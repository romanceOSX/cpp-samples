#include <algorithm>
#include <iostream>
#include <ranges>

constexpr int add_values(int a, int b) {
    int sum = a + b;
    return sum;
}

int main (int argc, char *argv[]) {
    std::cout << "Constexpr sample" << std::endl;   
    
    constexpr int val1 = 2;
    int a[add_values(val1, 2)] = {};
    
    std::ranges::for_each(a, [](auto& e) { std::cout << "- " << e << std::endl; });

    return 0;
}

