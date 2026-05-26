#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace read_impl {
// TODO
}

template<typename T>
T read(std::istream &is) {
    return TODO;
}

int main() {
    std::stringstream s(
        "1 "
        "hello "
        "2 1.5 4.5 "
        "10 "
        "2 "
        "1 1.5 "
        "2 2.5 3.5"
    );
    assert(read<int>(s) == 1);
    assert(read<std::string>(s) == "hello");
    assert(read<std::vector<double>>(s) == (std::vector{1.5, 4.5}));
    assert(read<int>(s) == 10);
    assert(read<std::vector<std::vector<double>>>(s) == (std::vector{std::vector{1.5}, std::vector{2.5, 3.5}}));
    std::cout << "OK\n";
}
