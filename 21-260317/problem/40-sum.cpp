#include <cassert>
#include <numeric>
#include <vector>

int main() {
    std::vector v{1, 2, 3, 4, 5};
    assert(TODO(v.begin(), v.end(), TODO) == 15);
}
