#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> data = {4, 2, 1, 3, 5};
    std::sort(data.begin(), data.end(), [](const int& lhs, const int& rhs) {
        return lhs > rhs;
    });

    assert(data[0] == 5);
    assert(data[1] == 4);
    assert(data[2] == 3);
    assert(data[3] == 2);
    assert(data[4] == 1);

    std::cout << "All good!" << std::endl;
}
