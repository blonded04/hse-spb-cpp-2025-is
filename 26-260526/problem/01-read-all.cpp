#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>

void read(std::istream &is, int &v) {
    is >> v;
}

template<typename T>
void read(std::istream &is, std::vector<T> &v) {
    int n;
    is >> n;
    v.resize(n);
    for (T &x : v) {
        read(is, x);
    }
}

// TODO: implement readAll()

int main() {
    std::stringstream s(R"(
    10 20
    3
    1 2 3
    30
    )");

    int a, b, c;
    std::vector<int> vec;
    readAll(s, a, b, vec, c);
    assert(a == 10);
    assert(b == 20);
    assert((vec == std::vector{1, 2, 3}));
    assert(c == 30);
    std::cout << "OK\n";
}
