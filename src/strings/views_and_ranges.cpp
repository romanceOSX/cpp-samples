//--> https://hannes.hauswedell.net/post/2019/11/30/range_intro/

#include <iostream>
#include <string>
#include <ranges>
#include <algorithm>

void test_views() {
    std::string s{"Hello Earth"};
    auto v = std::views::reverse(s);
    //std::ranges::remove(s, ' ');
    std::cout << v << std::endl;
}

