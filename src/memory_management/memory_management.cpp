#include <iostream>
#include <memory>

class Foo {
    public:
        /* default constructor */
        Foo();
        /* constructor with arguments */
        Foo(int a, int b, int& c);
        ~Foo();
};

Foo::Foo() {
    std::cout << "☀️ Creating Foo" << std::endl;
}

Foo::Foo(int a, int b, int& c) {
    std::cout << "☀️ Creating Foo with custom arguments" << std::endl;
}

Foo::~Foo() {
    std::cout << "🌙 Destroying Foo" << std::endl;
}

int main (int argc, char *argv[]) {
    std::unique_ptr<Foo> pf_default = std::make_unique<Foo>();
    int my_int = 32;
    std::unique_ptr<Foo> pf_custom = std::make_unique<Foo>(1, 2, my_int);
    return 0;
}
