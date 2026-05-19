#include <cassert>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>
#include <utility>
#include <vector>

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void findPrimes(int begin, int end, std::promise<std::vector<int>> result) {
    std::vector<int> found;
    for (int i = begin; i < end; i++)
        if (isPrime(i)) {
            found.push_back(i);
        }
    result.set_value(found);
}

int main() {
    const int N = 10'000'000;
    const int K = 4;

    auto start = std::chrono::steady_clock::now();
    std::vector<std::pair<std::thread, std::future<std::vector<int>>>> ts;
    for (int i = 0; i < K; i++) {
        std::promise<std::vector<int>> p;
        ts.emplace_back(
            std::thread(findPrimes, N * i / K, N * (i + 1) / K, std::move(p)),
            p.get_future()
        );
    }

    std::vector<int> primes;
    for (auto &[t, f] : ts) {
        t.join();
        auto thread_primes = f.get();
        primes.insert(primes.end(), thread_primes.begin(), thread_primes.end());
    }
    std::cout << primes.size() << "\n";
    std::cout << "Elapsed "
              << std::chrono::duration_cast<std::chrono::milliseconds>(
                     std::chrono::steady_clock::now() - start
                 )
                     .count()
              << "ms\n";
}
