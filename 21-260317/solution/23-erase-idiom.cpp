#include <algorithm>
#include <cassert>
#include <vector>

int main() {
    std::vector vec{1, 2, 3, 4, 5, 6, 7, 8};

    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) {
        return x % 2 == 0;
    }), vec.end());

    assert((vec == std::vector{1, 3, 5, 7}));
    return 0;
}
