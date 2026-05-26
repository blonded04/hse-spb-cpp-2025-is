#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

namespace secret {
template<typename T>
struct magic_struct {
    magic_struct *swapped_with = nullptr;

    friend void swap(magic_struct &a, magic_struct &b) {
        a.swapped_with = &b;
        b.swapped_with = &a;    
    }
};
}

template<typename T>
void swap_elementwise(std::vector<T> &a, std::vector<T> &b) {
    assert(a.size() == b.size());
    // TODO: swap individual elements of `a` and `b` instead of their buffers.
    std::swap(a, b);
}

int main() {
    {
        std::vector<int> a{1, 2, 3}, b{4, 5, 6};
        swap_elementwise(a, b);
        assert((a == std::vector{4, 5, 6}));
        assert((b == std::vector{1, 2, 3}));
    }
    {
        std::vector<secret::magic_struct<int>> a(3), b(3);
        swap_elementwise(a, b);
        assert(a[0].swapped_with == &b[0]);
        assert(a[1].swapped_with == &b[1]);
        assert(a[2].swapped_with == &b[2]);
        assert(b[0].swapped_with == &a[0]);
        assert(b[1].swapped_with == &a[1]);
        assert(b[2].swapped_with == &a[2]);
    }
    std::cout << "OK\n";
}
