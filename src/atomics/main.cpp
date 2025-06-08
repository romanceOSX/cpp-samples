
#include <atomic>
#include <iostream>

/*
 * operations on std::atomic_flag
 */

std::atomic_flag a = ATOMIC_FLAG_INIT;
int main(int argc, char* argv[]) {
    /* the first time it results in false because it is empty initialized */
    auto f1 = a.test_and_set();
    /* the second time it returns a 1 because someone else aleady initialized it */
    auto f2 = a.test_and_set();
    auto f3 = a.test_and_set();
    std::cout << "is it even running?" << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;
}

