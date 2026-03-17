#include <algorithm>
#include <cassert>
#include <vector>

int main() {
    std::vector v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::TODO(TODO, TODO, TODO);
    // 1 2 | 3 4 5 6 7 8 | 9 10
    //       | +-------+
    // v v   +-------v v
    // 1 2 | 5 6 7 8 3 4 | 9 10
    assert((v == std::vector{1, 2, 5, 6, 7, 8, 3, 4, 9, 10}));
}
