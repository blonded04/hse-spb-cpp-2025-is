#include "doctest.h"

struct my_int {
private:
    struct bit_reference {
    private:
        unsigned int &value;
        unsigned int mask;

    public:
        bit_reference(unsigned int &value, int bit) : value(value), mask(1 << bit) {}
        operator bool() const { return value & mask; }
        bool operator=(bool v) {
            if (v) {
                value |= mask;
            } else {
                value &= ~mask;
            }
            return *this;
        }
    };

public:
    unsigned int value = 0;

    bool operator[](int i) const {
        return value & (1 << i);
    }

    bit_reference operator[](int i) {
        return bit_reference(value, i);
    }
};

TEST_CASE("my_int") {
    my_int b{123};
    CHECK(b[0]);
    CHECK(b[1]);
    CHECK(!b[2]);
    CHECK(b[3]);
    CHECK(b[4]);
    CHECK(b[5]);
    CHECK(b[6]);
    CHECK(!b[7]);

    b[3] = 0;
    CHECK(b.value == 115);
    b[3] = 0;
    CHECK(b.value == 115);
    b[3] = 1;
    CHECK(b.value == 123);
    b[3] = 1;
    CHECK(b.value == 123);
}
