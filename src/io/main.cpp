#include <iostream>
#include <iomanip>
#include <string>

/*
 * remember that '<<' and '>>' are evaluated left to right
 */
void test_manipulators() {
    //std::cout << "Testing stuff " << 0 << " " << 1 << std::boolalpha << std::endl;
    //std::cout << std::hex << std::uppercase << "butterflies: " <<  0xfede <<  std::nouppercase << " " << 0xfafa << std::endl;
    //std::cout << "Testing stuff " << false << " " << true << std::noboolalpha << std::endl;
    std::cout << std::ends;
    std::cout << std::ends << "enabled std::ends!!" << std::endl;
    std::cout << std::setw(15) << std::setfill('*');
    std::cout << "huuh" << std::endl;
    std::cout << 123456789 << std::endl;
    std::cout << std::hex << 123456789 << std::endl;
    std::cout << std::dec << 123456789 << std::endl;
}

void test_getline() {
    while (true) {
        std::string tmp;
        std::getline(std::cin, tmp, 'o');
        std::cout << "Provided line!: " << tmp << std::endl;
    }
}

int main (int argc, char *argv[]) {
    //test_getline();
    test_manipulators();
    return 0;
}

