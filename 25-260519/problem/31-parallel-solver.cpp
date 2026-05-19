#include <chrono>
#include <iostream>

int main() {
    int tn;
    std::cin >> tn;

    auto start = std::chrono::steady_clock::now();
    for (int t = 0; t < tn; t++) {
        unsigned a, b, x0;
        int n;
        std::cin >> a >> b >> x0 >> n;

        for (int i = 0; i < n; i++) {
            unsigned x1 = a * x0 + b;
            x0 = x1;
        }

        std::cout << x0 << "\n";
    }

    std::cerr << "Elapsed "
              << std::chrono::duration_cast<std::chrono::milliseconds>(
                     std::chrono::steady_clock::now() - start
                 )
                     .count()
              << "ms\n";
}
