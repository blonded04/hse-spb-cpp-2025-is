#include "../doctest.h"
#include "ratio.inc.cpp"

TEST_CASE("Multiplication uses implicit conversion from int on the right") {
    // This test should work right away.
    ratio r = ratio(3, 2) * 4;
    CHECK(r.numerator() == 6);
    CHECK(r.denominator() == 1);
}

TEST_CASE("Multiplication uses implicit conversion from int on the left") {
    ratio r = 4 * ratio(3, 2);
    CHECK(r.numerator() == 6);
    CHECK(r.denominator() == 1);
}
