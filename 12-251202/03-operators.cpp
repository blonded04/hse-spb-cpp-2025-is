#include <string>
#include <type_traits>
#include <utility>
#include "doctest.h"

#define HAS_TESTS
#include "03-operators-foo.hpp"
#include "03-operators-foo.hpp"

#define TASK_01_EQUAL
#define TASK_02_EXPLICIT_CONVERSION_TO_INT
#define TASK_03_ADDITION_ASSIGNMENT_SIDE_EFFECT
#define TASK_04_ADDITION_ASSIGNMENT_RETURN

struct FieldTester {
    // Do not try to understand the implementation currently, it's for the very
    // last lectures of the year.
    template <typename T>
    static auto has_accessible_a(const T &t) -> decltype(t.a, true) {
        return true;
    }

    template <typename T>
    static auto has_accessible_a(const T &t) -> bool {
        return false;
    }

    template <typename T>
    static auto has_accessible_b(const T &t) -> decltype(t.b, true) {
        return true;
    }

    template <typename T>
    static auto has_accessible_b(const T &t) -> bool {
        return false;
    }
};

TEST_CASE("Foo has constructors from previous task") {
    [[maybe_unused]] Foo f1 = {"hello1", 10};
    [[maybe_unused]] Foo f2("hello2");
    [[maybe_unused]] Foo f3 = {12};

    // Should not compile, fields are private:
    // CHECK(f1.a == "hello1");
    // CHECK(f1.b == 10);
    CHECK_MESSAGE(
        !FieldTester::has_accessible_a(f1), "Field `a` should be private!"
    );
    CHECK_MESSAGE(
        !FieldTester::has_accessible_b(f1), "Field `b` should be private!"
    );
}

#ifdef TASK_01_EQUAL
TEST_CASE("Foo::operator== works with conversions") {
    Foo f = {10};
    // Hint: if operator== is ambiguous after adding conversion to `int`,
    // double-check that it is explicit.
    CHECK(f == 10);  // should become f == Foo(10)
    CHECK(10 == f);  // should become Foo(10) == f
    CHECK(!(f == 11));
    CHECK(!(11 == f));
}
#endif  // TASK_01_EQUAL

#ifdef TASK_02_EXPLICIT_CONVERSION_TO_INT
void check_foo_int(const Foo &f, int expected_b) {
    CHECK(static_cast<int>(f) == expected_b);
}

TEST_CASE("Foo is explicitly convertible to int") {
    Foo f1("hello1", 10);
    Foo f2("hello2", 11);

    CHECK(static_cast<int>(f1) == 10);
    check_foo_int(f2, 11);
    // Should not compile:
    // int i = f;
    CHECK(!std::is_convertible_v<Foo, int>);
}
#endif  // TASK_02_EXPLICIT_CONVERSION_TO_INT

#ifdef TASK_03_ADDITION_ASSIGNMENT_SIDE_EFFECT
TEST_CASE("Foo::operator+= increases left-hand side") {
    Foo f("a", 10);
    f += Foo("b", 20);

    auto p = static_cast<std::pair<std::string, int>>(f);
    CHECK(p.first == "ab");
    CHECK(p.second == 30);
}
#endif  // TASK_03_ADDITION_ASSIGNMENT_SIDE_EFFECT

#ifdef TASK_04_ADDITION_ASSIGNMENT_RETURN
TEST_CASE("Foo::operator+= returns left-hand side by non-const reference") {
    Foo f1("a", 10);
    Foo f2("b", 20);
    (f1 += f2) += Foo("c", 30);

    auto p1 = static_cast<std::pair<std::string, int>>(f1);
    auto p2 = static_cast<std::pair<std::string, int>>(f2);

    CHECK(p1.first == "abc");
    CHECK(p1.second == 60);
    CHECK(p2.first == "b");
    CHECK(p2.second == 20);
}
#endif  // TASK_04_ADDITION_ASSIGNMENT_RETURN
