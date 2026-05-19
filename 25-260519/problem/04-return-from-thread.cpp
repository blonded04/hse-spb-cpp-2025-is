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

void findPrimes(int begin, int end, TODO result) {
    std::vector<int> found;
    for (int i = begin; i < end; i++)
        if (isPrime(i)) {
            found.push_back(i);
        }
    result.TODO(TODO);
}

int main() {
    const int N = 10'000'000;
    const int K = 4;

    auto start = std::chrono::steady_clock::now();
    std::vector<std::pair<std::thread, TODO>> ts;
    for (int i = 0; i < K; i++) {
        TODO todo;
        ts.emplace_back(
            std::thread(findPrimes, N * i / K, N * (i + 1) / K, TODO), TODO
        );
    }

    std::vector<int> primes;
    for (auto &[t, f] : ts) {
        t.join();
        auto thread_primes = f.TODO();
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
