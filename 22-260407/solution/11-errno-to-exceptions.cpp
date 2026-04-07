#include <cassert>
#include <iostream>
#include <vector>
#include <sstream>

int read_number(std::istream &is) {
    std::string s;
    is >> s;
    if (s == "zero") {
        return 0;
    } else if (s == "one") {
        return 1;
    } else if (s == "two") {
        return 2;
    } else {
        throw std::ios_base::failure("expected 'zero', 'one' or 'two' token");
    }
}

std::vector<int> read_vector_numbers(std::istream &is) {
    int n;
    is >> n;
    std::vector<int> result(n);
    for (int &v : result)
        v = read_number(is);
    return result;
}

int main() {
    std::vector vec{1};

    std::stringstream str("3\nzero two one\n4\nzero zero");
    str.exceptions(std::ios_base::failbit | std::ios_base::badbit);

    vec = read_vector_numbers(str);
    assert((vec == std::vector{0, 2, 1}));

    try {
        vec = read_vector_numbers(str);
        assert(false);
    } catch (std::ios_base::failure &) {
        // As expected
    }
}
