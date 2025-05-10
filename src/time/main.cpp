#include <iostream>
#include <chrono>
#include <string>

/* the clock represents a specific epoch time (time point) and
 * a tick rate (certain duration)
 */
void _get_system_clock_info() {
    std::cout 
        << "Type of rep: " 
        << typeid(std::chrono::system_clock::rep).name()
        << std::endl;
    std::cout 
        << "Duration: " 
        << typeid(std::chrono::system_clock::duration).name()
        << std::endl;
    std::cout
        << "Current date: "
        << std::chrono::system_clock::now()
        << std::endl;
}

void _time_type_test() {
    using namespace std::chrono_literals;
    auto seconds = 1s;
    seconds++;
    std::cout << seconds << std::endl;
}

void _clock_test() {
    const auto system_time{std::chrono::system_clock::now()};
    const auto start{std::chrono::steady_clock::now()};
    const auto finish{std::chrono::steady_clock::now()};
    std::cout << "Time since epoch" << start.time_since_epoch() << std::endl;
    const std::chrono::duration<double> elapsed_seconds{finish-start};
    std::cout << "Steady clock now: " << elapsed_seconds << std::endl;
}

int main (int argc, char *argv[]) {
    _clock_test();
    //_get_system_clock_info();
    //_time_type_test();
    return 0;
}

