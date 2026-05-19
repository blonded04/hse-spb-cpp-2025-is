#include <cassert>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<int> primes;
std::mutex primes_m;

void findPrimes(int begin, int end) {
    for (int i = begin; i < end; i++)
        if (isPrime(i)) {
            std::unique_lock l(primes_m);
            primes.push_back(i);
        }
}

int main() {
    const int N = 10'000'000;
    const int K = 4;

    auto start = std::chrono::steady_clock::now();
    std::vector<std::thread> ts;
    for (int i = 0; i < K; i++) {
        ts.emplace_back(findPrimes, N * i / K, N * (i + 1) / K);
    }
    for (auto &t : ts) {
        t.join();
    }
    std::cout << primes.size() << "\n";
    std::cout << "Elapsed "
              << std::chrono::duration_cast<std::chrono::milliseconds>(
                     std::chrono::steady_clock::now() - start
                 )
                     .count()
              << "ms\n";
}
