#include <algorithm>
#include <cassert>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

struct data {
    int value;
    std::mutex m;
};

int main() {
    const int N = 1000;

    std::vector<data> v(N);
    for (int i = 0; i < N; i++) {
        v[i].value = i;
    }

    auto worker = [&]() {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (i != j) {
                    std::unique_lock l1(v[i].m);
                    std::unique_lock l2(v[j].m);
                    std::swap(v[i].value, v[j].value);
                }
    };

    std::thread t1(worker);
    std::thread t2(worker);
    t1.join();
    t2.join();

    std::cout << "OK\n";
}
