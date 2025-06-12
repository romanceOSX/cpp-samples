#include <algorithm>
#include <fstream>
#include <print>
#include <string>
#include <iostream>
#include <sstream>
#include <string_view>
#include <vector>
#include <ranges>

std::char_traits<char> ct;
std::string s;

void test_views() {
    std::string s{"Hello Earth"};
    auto v = std::views::reverse(s);
    //std::ranges::remove(s, ' ');
    //std::cout << v << std::endl;
}

void _test_replacing() {
    std::cout << s << std::endl;
    std::string s{"00-11-22-33-44-55-66"};
    auto v = std::remove(std::begin(s), std::end(s), '-');
    std::cout << std::string_view{std::begin(s), v} << std::endl;
}

void _test_parse() {
    std::string filename{"sample.txt"};
    std::ifstream f{filename};

    std::string in;
    std::getline(f, in);   
    //std::cout << in << std::endl;
    std::getline(f, in);   
    std::cout << in << std::endl;
    std::getline(f, in);   
    std::cout << in << std::endl;
    std::getline(f, in);   
    std::cout << in << std::endl;
    std::getline(f, in);   
}

/*
 * Consider having the following input
 * "a, b,, c ,, d,, e,,"
 * separate the string given a pattern p
 * if i = c[1]
 * if i + 1 = c[2]
 */
using string_container_t = std::vector<std::string>;

string_container_t parse_string(std::string& str, std::string& sep) {
    string_container_t res;

    auto i = str.find(sep);
    if (i == std::string::npos) {
        res.push_back(str);
    }

    size_t first = 0;
    while (i != std::string::npos) {
        res.push_back(
            str.substr(first, i)
        );
        i = str.find(sep, ++i); 
        first = i + 1;
    };

    return res;
}

void print_string_container(string_container_t& cont) {
    for (auto& string: cont) {
        std::cout << string << std::endl;
    }
}

void _test_pattern_parsing() {
    std::string s{"this, , sklfj, is my, thing"};
    std::string sep{","};
    auto res = parse_string(s, sep);
    print_string_container(res);
}

void _test_string() {
    std::string input_string{"THis, is the,, input , string"};
    std::string sep{"0x"};
    std::string line;
    std::stringstream ss{input_string};
    while (std::getline(ss, line, ',')) {
        std::cout << line << std::endl;
    }
}

void _test_getline() {
    /* test with output string stream simulating iostream */
    std::stringstream string_stream;
    string_stream << "heey, how, is, it, going";
    std::string s;
    std::getline(string_stream, s, ',');
    std::cout << s << std::endl;
    std::getline(string_stream, s, ',');
    std::cout << s << std::endl;
    std::getline(string_stream, s, ',');
    std::cout << s << std::endl;
    std::getline(string_stream, s, ',');
    std::cout << s << std::endl;
}

int main (int argc, char *argv[]) {
    //_test_parse();
    //_test_getline();
    //_test_string();
    //_test_pattern_parsing();
    //_test_replacing();
    test_views();
    return 0;
}

