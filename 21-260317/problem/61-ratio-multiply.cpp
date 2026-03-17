#include "../doctest.h"
#include "ratio.inc.cpp"

TEST_CASE("Multiplication works") {
    ratio r = ratio(3, 2) * ratio(5, 4);
    CHECK(r.numerator() == 15);
    CHECK(r.denominator() == 8);
}

TEST_CASE("Multiplication reduces the fraction") {
    ratio r = ratio(3, 2) * ratio(5, 6);
    CHECK(r.numerator() == 5);
    CHECK(r.denominator() == 4);
}

TEST_CASE("Multiplication assignment") {
    ratio r(3, 2);
    r *= ratio(5, 4);
    CHECK(r.numerator() == 15);
    CHECK(r.denominator() == 8);
}

TEST_CASE("Multiplication assignment return value") {
    ratio r(3, 2);
    auto &r2 = r *= ratio(5, 4);
    CHECK(&r == &r2);  // Ensure it is the same variable.
    CHECK(r2.numerator() == 15);
    CHECK(r2.denominator() == 8);
}
