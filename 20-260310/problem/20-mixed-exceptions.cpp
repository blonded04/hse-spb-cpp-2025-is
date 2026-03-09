#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main() {
    std::vector vec{10, 20, 33};
    try {
        std::string index_str;
        index_str = "123456789123456789";
        std::cout << vec.at(std::stoi(index_str)) << "\n";  // TODO: guess which line will be executed.
    } catch (std::out_of_range &) {
        std::cout << "Out-of-range error\n";
    } catch (std::exception &) {
        std::cout << "Some std::exception, probably std::invalid_argument\n";
    }
}
