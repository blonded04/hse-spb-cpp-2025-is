#include <algorithm>
#include <cassert>

int main() {
    assert(std::TODO(10, 20) == 10);
    assert(std::TODO(20, 10) == 10);

    assert(std::TODO(10, 20) == 20);
    assert(std::TODO(20, 10) == 20);

    assert(std::TODO(-10, 1, 5) == 1);
    assert(std::TODO(1, 1, 5) == 1);
    assert(std::TODO(2, 1, 5) == 2);
    assert(std::TODO(3, 1, 5) == 3);
    assert(std::TODO(4, 1, 5) == 4);
    assert(std::TODO(5, 1, 5) == 5);
    assert(std::TODO(10, 1, 5) == 5);
}
