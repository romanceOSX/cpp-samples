#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

// C++20
#include <filesystem>
namespace fs = std::filesystem;

// non C++20
std::string read_file(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in)
        std::runtime_error("Failed to open file!");

    return std::string (
        std::istreambuf_iterator<char>(in),
        std::istreambuf_iterator<char>()
    );
}

// C++ 20
std::string readFileCpp20(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in)
        std::runtime_error("Failed to open file!");

    std::string buffer(fs::file_size(path), '\0');
    in.read(buffer.data(), buffer.size());

    return buffer;
}

int main (int argc, char *argv[]) {
    std::cout << "doing input file" << std::endl;
    //std::string f = read_file("main.cpp");
    std::string f = readFileCpp20("main.cpp");
    std::cout << f << std::endl;
    return 0;
}
