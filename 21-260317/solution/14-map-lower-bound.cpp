#include <cassert>
#include <map>

const int N = 1'000'000;

int get_or_next(const std::map<int, int> &m, int key) {
    return m.lower_bound(key)->second;
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
