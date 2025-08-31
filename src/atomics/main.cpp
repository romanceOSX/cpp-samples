#include <atomic>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

/* barebones spinlock implementation */
class SpinLockMutex {
public:
    SpinLockMutex() = default;
    void lock() {
        /* if the value is true, then keep looping since some thread has marked it as busy */
        while(m_af.test_and_set());
    }
    void unlock() {
        m_af.clear();
    }
private:
    std::atomic_flag m_af = ATOMIC_FLAG_INIT;
};

/*
 * operations on std::atomic_flag
 */

static SpinLockMutex m;

void waiting_thread() {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "Waiting for resource to be available..." << std::endl;
    m.lock();
    std::cout << "finally got the resource!" << std::endl;
}

void actor_thread() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Locking resource..." << std::endl;
    m.lock();
    std::this_thread::sleep_for(std::chrono::seconds(15));
    std::cout << "Releasing resource!" << std::endl;
    m.unlock();
}

void _test_spin_lock_mutex() {
    std::vector<std::thread> threads;
    threads.emplace_back(actor_thread);
    threads.emplace_back(waiting_thread);

    for (auto& thread: threads) {
        thread.join();
    }
}

void _test_atomic_flag() {
    std::atomic_flag a = ATOMIC_FLAG_INIT;
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

void test_atomics() {
    std::atomic_flag f{ATOMIC_FLAG_INIT};
    std::cout << std::atomic_char::is_always_lock_free << std::endl;
}

void test_atomic_bool() {
    std::atomic_bool b;
    bool res = b.load(std::memory_order_acquire);
    std::cout << std::format("Value of bool: {}", res) << std::endl;
    b.store(true);
    res = b.exchange(false, std::memory_order_acquire);
    std::cout << std::format("Value of bool: {}", res) << std::endl;
    b.store(true);
    res = b.exchange(false, std::memory_order_acquire);
    std::cout << std::format("Value of bool: {}", res) << std::endl;
}

int main(int argc, char* argv[]) {
    //_test_atomic_flag();
    //_test_spin_lock_mutex();
    //test_atomics();
    test_atomic_bool();
}

