#include "../doctest.h"
#include "ratio.inc.cpp"

TEST_CASE("Constructed with two arguments") {
    ratio r(10, 3);
    CHECK(r.numerator() == 10);
    CHECK(r.denominator() == 3);
}

TEST_CASE("Constructed with one argument") {
    ratio r(10);
    CHECK(r.numerator() == 10);
    CHECK(r.denominator() == 1);
}

TEST_CASE("Implicitly copy-constructed from an int") {
    ratio r = 10;
    CHECK(r.numerator() == 10);
    CHECK(r.denominator() == 1);
}

TEST_CASE("Default constructed to zero") {
    ratio r;
    CHECK(r.numerator() == 0);
    CHECK(r.denominator() == 1);
}

TEST_CASE("Getters work on const object") {
    const ratio r(10, 3);
    CHECK(r.numerator() == 10);
    CHECK(r.denominator() == 3);
}
