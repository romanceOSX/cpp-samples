#include <iostream>

int main (int argc, char *argv[]) {
    try {
        throw 3;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    catch (...) {
        std::cout 
            << "I really don't know what failed..."
            << std::endl;
    }
    
    return 0;
}
