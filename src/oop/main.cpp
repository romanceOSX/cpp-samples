#include <iostream>

class Foo {
public: 
    void init(bool isDelete) {
        std::cout << isDelete << std::endl;
    }
};

int main(int argc, char* argv[]) {
    Foo f{};
    f.init();
}

