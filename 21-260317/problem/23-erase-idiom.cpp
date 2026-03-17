#include <algorithm>
#include <cassert>
#include <vector>

int main() {
    std::vector vec{1, 2, 3, 4, 5, 6, 7, 8};

    vec.erase(TODO, TODO);  // Call std::remove_if to remove even elements and truncate vector.

    assert((vec == std::vector{1, 3, 5, 7}));
    return 0;
}
