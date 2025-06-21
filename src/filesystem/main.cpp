#include <iostream>
#include <filesystem>
#include <mach-o/dyld.h>

namespace filesystem = std::filesystem;

void _test_macos_current_path() {
    char buffer[PATH_MAX];
    uint32_t path_size = sizeof(buffer);

    if (_NSGetExecutablePath(buffer, &path_size) == -1) {
        std::cerr << "Something went wrong allocating the buffer" << std::endl;
    };

    std::cout << "current executable path: " << buffer << std::endl;
}

int main (int argc, char *argv[]) {
    auto cpath = filesystem::current_path();
    std::cout << "current working directory: " << cpath << std::endl;
    _test_macos_current_path();
    return 0;
}

