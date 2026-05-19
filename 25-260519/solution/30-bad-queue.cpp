#include <iostream>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>

struct almost_safe_queue {
private:
    std::queue<int> q;
    mutable std::mutex m;

public:
    void push(int x) {
        std::unique_lock l(m);
        q.push(x);
    }

    std::optional<int> pop() {
        std::unique_lock l(m);
        if (q.empty()) {
            return std::nullopt;
        }
        int result = q.back();
        q.pop();
        return result;
    }
};

int main() {
    almost_safe_queue q;

    const int N = 1'000'000;
    const int K = 4;

    for (int i = 0; i < N; i++) {
        q.push(i);
    }

    std::vector<std::thread> ts;
    for (int i = 0; i < K; i++) {
        ts.emplace_back([&]() {
            int processed = 0;
            unsigned sum = 0;
            while (auto v = q.pop()) {
                sum += *v;
                processed++;
            }
            std::cout << processed << " " << sum << "\n";
        });
    }
    for (auto &t : ts) {
        t.join();
    }
}
