#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wexceptions"
#endif
#ifdef _MSC_VER
#pragma warning( disable : 4286 )
#endif

int main() {
    std::vector vec{10, 20, 33};
    try {
        std::string index_str;
        std::cin >> index_str;
        // TODO: fix the bug below so the behavior is as follows:
        // Expected outcomes:
        // 0 --> 10
        // 3 --> Out-of-range error
        // foo --> Some std::exception, probably std::invalid_argument
        std::cout << vec.at(std::stoi(index_str)) << "\n";
    } catch (std::exception &) {
        std::cout << "Some std::exception, probably std::invalid_argument\n";
    } catch (std::out_of_range &) {
        std::cout << "Out-of-range error\n";
    }
}
