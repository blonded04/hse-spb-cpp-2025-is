#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

template<typename T>
class threadsafe_queue {
    std::mutex m;
    std::queue<T> q;
    std::condition_variable q_non_empty;

public:
    void push(T value) {
        std::unique_lock l(m);
        q.emplace(std::move(value));
        q_non_empty.notify_one();
    }

    T pop() {
        std::unique_lock l(m);
        q_non_empty.wait(l, [this]() {
            return !q.empty();
        });
        T res = q.front();
        q.pop();
        return res;
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
