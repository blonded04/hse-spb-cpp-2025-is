#include <algorithm>
#include <cassert>
#include <vector>

int main() {
    std::vector<std::vector<int>> data{
        {1, 2, 3},
        {4, 5},
        {6, 7, 8, 9},
        {6, 7, 0, 0},
        {6, 7, 10, 10},
        {1, 1, 1, 1, 1},
    };
    // Sort by: a) length; b) content lexicographically.
    sort(data.begin(), data.end(), TODO);

    assert((data == std::vector<std::vector<int>>{
        {4, 5},
        {1, 2, 3},
        {6, 7, 0, 0},
        {6, 7, 8, 9},
        {6, 7, 10, 10},
        {1, 1, 1, 1, 1},
    }));
}
