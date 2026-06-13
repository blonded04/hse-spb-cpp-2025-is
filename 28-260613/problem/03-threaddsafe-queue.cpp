#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

// TODO:
// 1. Check if threadsafe_queue works already, compile with optimizations.
//     * Possible behavior on Windows (MinGW): `pop()` returns even if the queue is empty.
//     * Possible behavior: `pop()` is optimized out and never returns.
// 2. Make threadsafe_queue actually threadsafe (`mutex` is helpful).
// 3. Ensure `pop()` does not consume CPU (`condition_variable is helpful).
// Modify the class below only.

template<typename T>
class threadsafe_queue {
    std::queue<T> q;

public:
    void push(T value) {
        q.emplace(std::move(value));
    }

    T pop() {
        for (;;) {
            if (!q.empty()) {
                T res = q.front();
                q.pop();
                return res;
            }
        }
    }
};

int main() {
    threadsafe_queue<int> q;
    std::thread worker([&q]() {
        for (;;) {
            int value = q.pop();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout << "computed: " << value + 1 << std::endl;
        }
    });

    for (;;) {
        int value;
        std::cin >> value;
        q.push(value);
    }
}
