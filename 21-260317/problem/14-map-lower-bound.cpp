#include <cassert>
#include <map>

const int N = 1'000;  // TODO: replace with 1 million and ensure time limit exceeded.

int get_or_next(const std::map<int, int> &m, int key) {
    // TODO: use map::lower_bound member function instead for O(log n) instead of O(n).
    return lower_bound(m.begin(), m.end(), std::pair<const int, int>{key, 0})->second;
}

int main() {
    std::map<int, int> m;
    for (int i = 0; i < N; i++) {
        m.emplace(2 * i, i);
    }

    for (int i = 0; i + 1 < N; i++) {
        assert(get_or_next(m, 2 * i + 1) == i + 1);
    }

    assert(N == 1'000'000);
}
