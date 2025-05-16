#include <vector>
#include <iostream>
#include <map>

using StringMap = std::map<std::string, std::string>;

void _map_test() {
    StringMap sm{{"Hello", "world"}};

    sm.insert({"a", "b"});

    for (auto& [k, v]: sm) {
        std::cout << k << " : " << v << std::endl;
    }
}

void _vector_test() {
    std::vector<int> vi = {1, 2, 3, 4, 5};   
    std::cout << vi.at(0) << std::endl;
}

int main (int argc, char *argv[]) {
    _map_test();
    return 0;
}

