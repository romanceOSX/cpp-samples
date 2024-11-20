#include <iostream>

template <typename... Args>
void foo(Args... args) {
    std::cout << "Not default case" << std::endl;   
}

template <>
void foo<>() {
    std::cout << "default case" << std::endl;
}

/* default empty case */
void dbg_print() {

}

/* 
 * function that prints anything that has ostream::operator << overload 
 * "Iterates" over parameters thorough recursion
 */
template <typename T, typename... Args>
constexpr void dbg_print(T arg, Args... args) {
    std::cout << arg;
    /* recursively print the next ones */
    dbg_print(args...);
}

int main (int argc, char *argv[]) {
    foo(2);
    foo();
    dbg_print(1, "hey", 2.2, "howw", "\n");
    return 0;
}

