#include <cassert>
#include <iostream>
#include <vector>
#include <sstream>

// TODO: rewrite the code such that:
// 1. Exceptions are used instead of return codes, including for iostream errors.
// 2. read_number/read_vector_numbers return values instead of using output parameter.

bool read_number(std::istream &is, int &out) {
    std::string s;
    if (!(is >> s)) {
        return false;
    }
    if (s == "zero") {
        out = 0;
        return true;
    } else if (s == "one") {
        out = 1;
        return true;
    } else if (s == "two") {
        out = 2;
        return true;
    } else {
        return false;
    }
}

bool read_vector_numbers(std::istream &is, std::vector<int> &out) {
    int n;
    if (!(is >> n)) {
        return false;
    }
    out.resize(n);
    for (int &value : out)
        if (!read_number(is, value)) {
            return false;
        }
    return true;
}

int main() {
    std::vector vec{1};

    std::stringstream str("3\nzero two one\n4\nzero zero");

    assert(read_vector_numbers(str, vec));
    assert((vec == std::vector{0, 2, 1}));

    assert(!read_vector_numbers(str, vec));
}
