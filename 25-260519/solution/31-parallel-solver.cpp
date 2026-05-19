#include <chrono>
#include <iostream>
#include <thread>
#include <utility>
#include <vector>

std::vector<unsigned> results;

void solve(unsigned a, unsigned b, unsigned x0, int n, int t) {
    for (int i = 0; i < n; i++) {
        unsigned x1 = a * x0 + b;
        x0 = x1;
    }
    results[t] = x0;
}

int main() {
    int tn;
    std::cin >> tn;

    auto start = std::chrono::steady_clock::now();

    std::vector<std::thread> ts;
    results.resize(tn);
    for (int t = 0; t < tn; t++) {
        unsigned a, b, x0;
        int n;
        std::cin >> a >> b >> x0 >> n;
        ts.emplace_back(solve, a, b, x0, n, t);
    }

    for (auto &t : ts) {
        t.join();
    }
    for (auto result : results) {
        std::cout << result << "\n";
    }
    std::cerr << "Elapsed "
              << std::chrono::duration_cast<std::chrono::milliseconds>(
                     std::chrono::steady_clock::now() - start
                 )
                     .count()
              << "ms\n";
}
