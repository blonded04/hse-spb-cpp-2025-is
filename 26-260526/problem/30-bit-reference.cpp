#include "doctest.h"

struct my_int {
private:
    struct bit_reference {
    private:
        // TODO: add fields

    public:
        bit_reference(TODO) {}  // TODO
        operator bool() const { TODO }
        bool operator=(bool v) {
            TODO
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
