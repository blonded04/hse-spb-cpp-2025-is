#include <iostream>
#include <mutex>
#include <thread>

int main() {
    std::thread t([]() {
        for (;;) {
            // On some systems (e.g. msys2) std::cout seems to not
            // easily interleave string literals with each other,
            // so we print two literals in this exercise.
            std::cout << "Hello "
                      << "World\n";
        }
    });
    for (;;) {
        std::cout << "2 + 2 = "
                  << "4\n";
    }
}
