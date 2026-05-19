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

    int pop() {
        std::unique_lock l(m);
        int result = q.back();
        q.pop();
        return result;
    }

    std::size_t size() const {
        std::unique_lock l(m);
        return q.size();
    }
};

int main() {
    almost_safe_queue q;

    const int N = 10'000'000;
    const int K = 4;

    for (int i = 0; i < N; i++) {
        q.push(i);
    }

    std::vector<std::thread> ts;
    for (int i = 0; i < K; i++) {
        ts.emplace_back([&]() {
            int processed = 0;
            unsigned sum = 0;
            while (q.size() > 0) {
                sum += q.pop();
                processed++;
            }
            std::cout << processed << " " << sum << "\n";
        });
    }
    for (auto &t : ts) {
        t.join();
    }
}
