#include "optional.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <type_traits>
#include <utility>
#include "doctest.h"

#define OPTIONAL_TEST_INIT
#define OPTIONAL_TEST_OWNERSHIP
#define OPTIONAL_TEST_RESET
#define OPTIONAL_TEST_MOVABLE
#define OPTIONAL_TEST_COPYABLE
#define OPTIONAL_TEST_VALUE
#define OPTIONAL_TEST_REASSIGN

#ifdef TEST_STD_OPTIONAL
using std::optional;
#else
using ex_optional::optional;
#endif

#ifdef OPTIONAL_TEST_INIT
TEST_CASE(
    "Default-initialize "
#ifdef TEST_STD_OPTIONAL
    "std::optional<std::string>"
#else
    "ex_optional::optional<std::string>"
#endif
    " and non-constructible") {
    optional<std::string> x;
    CHECK(!x.has_value());

    struct NonConstructible {
        NonConstructible() = delete;
    };
    optional<NonConstructible> y;
    CHECK(!y.has_value());
}

TEST_CASE("Default-copy-initialize") {
    optional<std::string> x = {};
    CHECK(!x.has_value());

    struct NonConstructible {
        NonConstructible() = delete;
    };
    optional<NonConstructible> y = {};
    CHECK(!y.has_value());
}

TEST_CASE("Copy-initialize from value") {
    std::string s(10000, 'x');
    optional<std::string> x = s;
    REQUIRE(x.has_value());
    CHECK(x.value() == std::string(10000, 'x'));
    CHECK(s == std::string(10000, 'x'));

    struct CopyOnly {
        int val;
        CopyOnly(int val_) : val(val_) {
        }
    };
    // std::optional works with just `y = 20`, but it requires a bit of metaprogramming.
    CopyOnly copy_val(20);
    optional<CopyOnly> y = copy_val;
    REQUIRE(y.has_value());
    CHECK(y.value().val == 20);
}

TEST_CASE("Correctly aligned") {
    static constexpr auto ALIGNMENT =
        std::max(alignof(std::max_align_t) * 2, static_cast<std::size_t>(32));
    struct alignas(ALIGNMENT) AlignmentChecker {
        AlignmentChecker() {
            // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
            CHECK(reinterpret_cast<std::uintptr_t>(this) % ALIGNMENT == 0);
        }
        AlignmentChecker(const AlignmentChecker &) : AlignmentChecker() {
        }
        AlignmentChecker(AlignmentChecker &&) : AlignmentChecker() {
        }
        AlignmentChecker &operator=(const AlignmentChecker &) = default;
        AlignmentChecker &operator=(AlignmentChecker &&) = default;
        ~AlignmentChecker() = default;
    };
    optional<AlignmentChecker> x[]{AlignmentChecker(), AlignmentChecker(),
                                   AlignmentChecker(), AlignmentChecker()};
    REQUIRE(x[0].has_value());
    REQUIRE(x[1].has_value());
    REQUIRE(x[2].has_value());
    REQUIRE(x[3].has_value());
}
#endif  // OPTIONAL_TEST_INIT

#ifdef OPTIONAL_TEST_OWNERSHIP
TEST_CASE("Optional owns the object") {
    int destructors = 0;
    // NOLINTNEXTLINE(cppcoreguidelines-special-member-functions)
    struct DestructCounter {
        int *destructorsCounter;

        ~DestructCounter() {
            ++*destructorsCounter;
        }
    };

    {
        DestructCounter counter{&destructors};
        // cppcheck-suppress knownConditionTrueFalse
        REQUIRE(destructors == 0);
        {
            optional<DestructCounter> x(counter);
            static_cast<void>(x);
            CHECK(destructors == 0);
        }
        CHECK(destructors == 1);
    }
    CHECK(destructors == 2);
}
#endif  // OPTIONAL_TEST_OWNERSHIP

#ifdef OPTIONAL_TEST_RESET
TEST_CASE("reset() works for empty optional") {
    optional<std::string> x;
    x.reset();
    CHECK(!x.has_value());
    x.reset();
    CHECK(!x.has_value());
}

TEST_CASE("reset() works for non-empty optional") {
    optional<std::string> x(std::string(10000, 'x'));
    x.reset();
    CHECK(!x.has_value());
    x.reset();
    CHECK(!x.has_value());
}
#endif  // OPTIONAL_TEST_RESET

#ifdef OPTIONAL_TEST_COPYABLE
TEST_CASE("optional is copyable") {
    optional<std::string> empty;
    optional<std::string> withData(std::string(10000, 'x'));

    SUBCASE("copy-constructible from empty") {
        // NOLINTNEXTLINE(performance-unnecessary-copy-initialization)
        optional x = empty;
        CHECK(!empty.has_value());
        CHECK(!x.has_value());
    }

    SUBCASE("copy-assignable from empty to empty") {
        optional<std::string> x;
        CHECK(&(x = empty) == &x);
        CHECK(!empty.has_value());
        CHECK(!x.has_value());
    }

    SUBCASE("copy-assignable from empty to data") {
        optional x(std::string(10000, 'y'));
        CHECK(&(x = empty) == &x);
        CHECK(!empty.has_value());
        CHECK(!x.has_value());
    }

    SUBCASE("self copy-assignable when empty") {
        CHECK(&(empty = empty) == &empty);
        CHECK(!empty.has_value());

        CHECK(&(empty = empty) == &empty);
        CHECK(!empty.has_value());
    }

    SUBCASE("copy-constructible from data") {
        optional x = withData;
        REQUIRE(withData.has_value());
        CHECK(withData.value() == std::string(10000, 'x'));
        REQUIRE(x.has_value());
        CHECK(x.value() == std::string(10000, 'x'));
    }

    SUBCASE("copy-assignable from data to empty") {
        optional<std::string> x;
        CHECK(&(x = withData) == &x);
        REQUIRE(withData.has_value());
        CHECK(withData.value() == std::string(10000, 'x'));
        REQUIRE(x.has_value());
        CHECK(x.value() == std::string(10000, 'x'));
    }

    SUBCASE("copy-assignable from data to data") {
        optional x(std::string(10000, 'y'));
        CHECK(&(x = withData) == &x);
        REQUIRE(withData.has_value());
        CHECK(withData.value() == std::string(10000, 'x'));
        REQUIRE(x.has_value());
        CHECK(x.value() == std::string(10000, 'x'));
    }

    SUBCASE("self copy-assignable when has data") {
        CHECK(&(withData = withData) == &withData);
        REQUIRE(withData.has_value());
        CHECK(withData.value() == std::string(10000, 'x'));

        CHECK(&(withData = withData) == &withData);
        REQUIRE(withData.has_value());
        CHECK(withData.value() == std::string(10000, 'x'));
    }
}
#endif  // OPTIONAL_TEST_COPYABLE
