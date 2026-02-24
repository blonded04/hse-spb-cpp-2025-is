#include "storage.hpp"
#include <iostream>

int main() {
    for (int val : exercise::get_numbers()) {
        std::cout << val << "\n";
    }
}
