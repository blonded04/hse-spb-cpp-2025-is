#include <algorithm>
#include <cassert>
#include <vector>
#include <utility>

int main() {
    std::vector<std::pair<int, int>> v{
        {1, 1},
        {1, 2},
        {1, 3},
        {2, 1},
        {2, 2},
        {2, 3},
        {3, 1},
        {3, 2},
        {3, 3},
    };

    sort(v.begin(), v.end(), TODO);

    assert((v == std::vector<std::pair<int, int>>{
        {3, 1},
        {3, 2},
        {3, 3},
        {2, 1},
        {2, 2},
        {2, 3},
        {1, 1},
        {1, 2},
        {1, 3},
    }));
}
