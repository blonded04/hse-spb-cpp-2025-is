#include <cassert>
#include <iostream>

template<typename ...Ts>
int find_int(const int &x, const Ts &...) {
    return x;
}

template<typename T, typename ...Ts>
int find_int(const T &, const Ts &...ts) {
    return find_int(ts...);
}

int main() {
    assert(find_int(1.0, 2, "3", 4) == 2);
    assert(find_int(2, "3", 4) == 2);
    assert(find_int("3", 4) == 4);
    std::cout << "OK\n";
}
