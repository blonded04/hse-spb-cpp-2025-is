#include "doctest.h"
#include <cstddef>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

struct vector_size_mismatch : std::runtime_error {
private:
    vector_size_mismatch(std::size_t lhs, std::size_t rhs)
        : std::runtime_error("vector size mismatch: " + std::to_string(lhs) + " != " + std::to_string(rhs)) {}

public:
    template<typename T>
    friend void ensure_same_size(const std::vector<T> &lhs, const std::vector<T> &rhs) {
        if (lhs.size() != rhs.size()) {
            throw vector_size_mismatch(lhs.size(), rhs.size());
        }
    }
};
template<typename T> void ensure_same_size(const std::vector<T> &lhs, const std::vector<T> &rhs);

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
