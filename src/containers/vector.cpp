#include <vector>
#include <iostream>

int main (int argc, char *argv[]) {
    std::vector<int> vi = {1, 2, 3, 4, 5};   
    std::cout << vi.at(0) << std::endl;
    return 0;
}

