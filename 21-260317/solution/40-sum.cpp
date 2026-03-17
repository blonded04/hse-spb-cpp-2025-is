#include <cassert>
#include <numeric>
#include <vector>

int main() {
    std::vector v{1, 2, 3, 4, 5};
    assert(std::accumulate(v.begin(), v.end(), 0) == 15);
}
