#include <cassert>
#include <exception>
#include <iostream>
#include <vector>

std::vector<int> sum(const std::vector<int> &lhs, const std::vector<int> &rhs) {
    assert(lhs.size() == rhs.size());
    std::vector<int> result(lhs.size());
    for (std::size_t i = 0; i < lhs.size(); i++) {
        result[i] = lhs[i] + rhs[i];
    }
    return result;
}

void print(const std::vector<int> &v) {
    for (std::size_t i = 0; i < v.size(); i++) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << v[i];
    }
}

int main() {
    std::vector<std::vector<int>> vecs{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9, 10},
        {11, 12, 13, 14},
    };
    int a, b;
    while (std::cin >> a >> b) {
        // TODO: add try-block around following two lines and print std::exception's message. For loop will have 6 lines of code.
        print(sum(vecs[a], vecs[b]));  // TODO: make this expression throw exception on out-of-bounds. Hint: see "See also" in for `operator[]`
        std::cout << "\n";
    }
}
