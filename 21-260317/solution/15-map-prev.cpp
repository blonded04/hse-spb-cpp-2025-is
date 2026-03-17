#include <cassert>
#include <iterator>
#include <map>

const int N = 1'000'000;

int get_or_prev(const std::map<int, int> &m, int key) {
    return std::prev(m.upper_bound(key))->second;
}

int main() {
    std::map<int, int> m;
    for (int i = 0; i < N; i++) {
        m.emplace(2 * i, i);
    }

    for (int i = 0; i < N; i++) {
        assert(get_or_prev(m, 2 * i) == i);
        assert(get_or_prev(m, 2 * i + 1) == i);
    }

    assert(N == 1'000'000);
}
