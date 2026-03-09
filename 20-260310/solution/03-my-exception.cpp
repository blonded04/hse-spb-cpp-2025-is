#include <cassert>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

struct vector_size_mismatch : std::runtime_error {
    // More complex alternative: inherit from std::exception and store std::string.
    // Careful with 'class': it will make private inheritance.
    // Careful with applying c_str() to a temporary string.
    vector_size_mismatch(std::size_t lhs, std::size_t rhs)
        : std::runtime_error("vector size mismatch: " + std::to_string(lhs) + " != " + std::to_string(rhs)) {}
};

std::vector<int> sum(const std::vector<int> &lhs, const std::vector<int> &rhs) {
    if (lhs.size() != rhs.size()) {
        throw vector_size_mismatch(lhs.size(), rhs.size());
    }
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
        try {
            print(sum(vecs.at(a), vecs.at(b)));
            std::cout << "\n";
        } catch (std::exception &e) {
            std::cout << e.what() << "\n";
        }
    }
}
