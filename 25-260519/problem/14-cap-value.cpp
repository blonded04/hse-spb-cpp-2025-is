#include <cassert>

auto is_divisible_by(int modulo) {
    return [& /* TODO */](int x) { return x % modulo == 0; };
}

int main() {
    {
        auto divisible_by_2 = is_divisible_by(2);
        assert(!divisible_by_2(1));
        assert(divisible_by_2(2));
        assert(!divisible_by_2(3));
        assert(divisible_by_2(4));
        assert(!divisible_by_2(5));
        assert(divisible_by_2(6));
        assert(sizeof(divisible_by_2) == sizeof(int));
    }
    {
        auto divisible_by_5 = is_divisible_by(5);
        assert(!divisible_by_5(1));
        assert(!divisible_by_5(2));
        assert(divisible_by_5(5));
        assert(!divisible_by_5(6));
        assert(!divisible_by_5(7));
        assert(!divisible_by_5(8));
        assert(divisible_by_5(10));
    }
}
