#include <algorithm>
#include <cassert>
#include <vector>

int main() {
    std::vector vec{1, 2, 3, 4, 5, 6, 7, 8};

    auto new_vec_end = std::remove_if(vec.begin(), vec.end(), [](int x) {
        return x % 2 == 0;
    });

    assert(vec.size() == 8);  // std::remove_if does not modify container.

    std::vector subvec(vec.begin(), new_vec_end);  // Create subvector
    assert((subvec == std::vector{1, 3, 5, 7}));
    return 0;
}
