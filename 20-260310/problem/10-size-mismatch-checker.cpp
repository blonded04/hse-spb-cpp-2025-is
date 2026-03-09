#include "doctest.h"
#include <cstddef>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

// TODO: create your own `vector_size_mismatch` class, but:
// 1. There is a `ensure_same_size` function which provides an easier interface to check for a condition and throw the exception if it's not held.
// 2. All constructors are private.
// 3. (hard) Uncomment the test with vector<double> and make `ensure_same_size` templated.

TEST_CASE("exception is derived from std::runtime_error") {
    // Check that inheritance is public, std::is_base_of checks for any inheritance
    CHECK(std::is_convertible_v<vector_size_mismatch*, std::runtime_error*>);
}

TEST_CASE("vector<int>") {
    const std::vector<int> a(3), b(3), c(4);
    ensure_same_size(a, b);
    ensure_same_size(b, a);
    CHECK_THROWS_WITH_AS(ensure_same_size(a, c), "vector size mismatch: 3 != 4", vector_size_mismatch);
    CHECK_THROWS_WITH_AS(ensure_same_size(c, a), "vector size mismatch: 4 != 3", vector_size_mismatch);
}

TEST_CASE("vector<double>") {
    const std::vector<double> a(3), b(3), c(4);
    ensure_same_size(a, b);
    ensure_same_size(b, a);
    CHECK_THROWS_WITH_AS(ensure_same_size(a, c), "vector size mismatch: 3 != 4", vector_size_mismatch);
    CHECK_THROWS_WITH_AS(ensure_same_size(c, a), "vector size mismatch: 4 != 3", vector_size_mismatch);
}
