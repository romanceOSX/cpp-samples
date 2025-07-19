#include <iostream>

class Foo{
public:
    explicit Foo(std::string& in_str):
        m_str(std::move(in_str)) {
        std::cout
            << "Given string inside Foo!: "
            << in_str
            << std::endl;
    }
private:
    std::string m_str;
};

int main (int argc, char *argv[]) {
    std::string s{"My string!"};
    Foo f(s);

    std::cout
        << "Printing string from main: "
        << s
        << std::endl;
    return 0;
}

