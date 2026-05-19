#include <algorithm>
#include <cassert>
#include <vector>

int main() {
    std::vector<int> data{
        5, 2, 3, 7, 4, 6, 8, 0, 9, 1
    };
    std::vector<int> bad_elements{
        3, 5, 8, 9
    };

    // See 03-210920/23-erase-idiom.cpp
    // Should be a single line and faster than O(nm)
    data.erase(std::remove_if(data.begin(), data.end(), [&](int value) {
        return std::binary_search(bad_elements.begin(), bad_elements.end(), value);
    }), data.end());

    assert((data == std::vector{2, 7, 4, 6, 0, 1}));
}
