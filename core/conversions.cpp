#include <iostream>

/*
 *  User-defined conversion functions
 *  --> https://en.cppreference.com/w/cpp/language/cast_operator
 */

class Foo {
    public:
        /* implicit user-defined conversion function 
         *  --> https://en.cppreference.com/w/cpp/language/cast_operator */
        operator int();
        operator float();

        Foo() = default;
        Foo(int i);
};

Foo::Foo(int i) {
    std::cout << "int constructor called!" << std::endl;
}

Foo::operator int() {
    std::cout << "implicit int operator called!" << std::endl;
    return 7;
}

Foo::operator float() {
    std::cout << "Explicit float operator called!" << std::endl;
    return 2.0;
}

/* function that expects an int */
void print_int(int i) {
    std::cout << "Printing your int!" << std::endl
        << i << std::endl;
}

int main (int argc, char *argv[]) {
    Foo f;
    Foo x = 1; // calls Foo(int) constructor conversion
    int a = f; // calls operator int()
    float my_float = f;  // calls operator float()
    print_int(f); // calls operator int()
    return 0;
}

