#include <iostream>
#include <utility>

using BitsType = uint32_t;

enum class FlagBits: BitsType {
    eEnabled,
    eDisabled,
    eUnknown,
};

int main (int argc, char *argv[]) {
    auto a = FlagBits::eDisabled;
    std::cout << std::hex << std::to_underlying(a) << std::endl;

    return 0;
}

