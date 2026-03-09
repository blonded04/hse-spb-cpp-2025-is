#include <boost/format.hpp>  // fmtlib is also nice, partially included in C++20
#include <exception>
#include <iostream>
#include <stdexcept>

struct not_equal_error : std::runtime_error {
    not_equal_error(int a, int b)
        : std::runtime_error(boost::str(boost::format("Expected equal numbers, got %1% != %2%") % a % b)) {}
};

void check_equal(int a, int b) {
    if (a != b) {
        throw not_equal_error(a, b);
    }
}

int main() {
    int a, b;
    while (std::cin >> a >> b) {
        try {
            check_equal(a, b);
            std::cout << a << "\n";
        } catch (not_equal_error &e) {
            std::cout << e.what() << "\n";
        }
    }
}
