#include <algorithm>
#include <cassert>
#include <vector>

int main() {
    std::vector vec{1, 2, 3, 4, 5, 6, 7, 8};

    TODO new_vec_end = TODO;  // Call std::remove_if to remove all even elements.

    assert(vec.size() == 8);  // std::remove_if does not modify container.

    std::vector subvec(TODO, TODO);  // Create subvector of remaining elements.
    assert((subvec == std::vector{1, 3, 5, 7}));
    return 0;
}
