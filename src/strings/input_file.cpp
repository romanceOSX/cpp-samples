#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

std::string read_file(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in)
        std::runtime_error("Failed to open file!");

    return std::string (
        std::istreambuf_iterator<char>(in),
        std::istreambuf_iterator<char>()
    );
}

int main (int argc, char *argv[]) {
    std::cout << "doing input file" << std::endl;
    std::string f = read_file("main.cpp");
    std::cout << f << std::endl;
    return 0;
}
