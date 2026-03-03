#include <chrono>
#include <functional>
#include <iostream>
#include <vector>

// TODO: begin
void measure_call(std::function<void()> functor) {
// TODO: end
    const auto clock_before = std::chrono::system_clock::now();
    functor();
    const auto clock_after = std::chrono::system_clock::now();

    const auto time_elapsed = 
        std::chrono::duration_cast<std::chrono::microseconds>(clock_after - clock_before);
    std::cout << "It took \"" << time_elapsed.count() << "\" microseconds to execute." << '\n';
}

int main() {
    std::function<void()> f1 = []() {
        return 5 + 3;
    };
    auto f2 = []() {
        const int SIZE = 1000;
        std::vector<int*> ptrs(SIZE);
        for (int i = 0; i < SIZE; i++) {
            ptrs[i] = new int[1000];
        }
        for (int i = 0; i < SIZE; i++) {
            delete[] ptrs[i];
        }
    };
    void (*f2_ptr)() = f2;

    // These lines should compile:
    measure_call(f1);                    // call via std::function
    measure_call(f2_ptr);                // call via function-pointer
    measure_call([&f1]() {               // call via lambda-function
        for (int i = 0; i <= 10; i++) {
            f1();
        }
    });
}
