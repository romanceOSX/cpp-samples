#include <fstream>
#include <string>
#include <iostream>

std::char_traits<char> ct;
std::string s;

void _test_parse() {
    std::string filename{"sample.txt"};
    std::ifstream f{filename, std::ios::binary};

    std::string in;
    std::getline(f, in);   
    //std::cout << f << std::endl;
}

int main (int argc, char *argv[]) {
    
    return 0;
}

