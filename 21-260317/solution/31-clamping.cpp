#include <algorithm>
#include <cassert>

int main() {
    assert(std::min(10, 20) == 10);
    assert(std::min(20, 10) == 10);

    assert(std::max(10, 20) == 20);
    assert(std::max(20, 10) == 20);

    assert(std::clamp(-10, 1, 5) == 1);
    assert(std::clamp(1, 1, 5) == 1);
    assert(std::clamp(2, 1, 5) == 2);
    assert(std::clamp(3, 1, 5) == 3);
    assert(std::clamp(4, 1, 5) == 4);
    assert(std::clamp(5, 1, 5) == 5);
    assert(std::clamp(10, 1, 5) == 5);
}
