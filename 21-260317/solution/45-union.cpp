#include <algorithm>
#include <cassert>
#include <vector>

int main() {
    std::vector<int> a{10, 20, 30, 40, 40};
    std::vector<int> b{5, 11, 12, 31, 33, 40, 45};
    std::vector<int> result(a.size() + b.size());

    result.erase(
        std::set_union(a.begin(), a.end(), b.begin(), b.end(), result.begin()),
        result.end());

    assert((result == std::vector{5, 10, 11, 12, 20, 30, 31, 33, 40, 40, 45}));
}
