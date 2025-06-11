#include <iostream>
#include <string>

// 00-00-00-00-00


int main (int argc, char *argv[]) {
    while (true) {
        std::string tmp;
        std::getline(std::cin, tmp, 'o');
        std::cout << "Provided line!: " << tmp << std::endl;
    }
    return 0;
}

