#include <sstream>
#include <string>
#include <type_traits>
#include <utility>
#include "doctest.h"

#define HAS_TESTS
#include "04-operators-extra-foo.hpp"
#include "04-operators-extra-foo.hpp"

#define TASK_01_INCREMENT_PREFIX
#define TASK_02_INCREMENT_POSTFIX
#define TASK_03_WRITE
#define TASK_04_READ

struct FieldTester {
    // Do not try to understand the implementation currently, it's for the very
    // last lectures of the year.
    template <typename T>
    static auto has_accessible_a(const T &t) -> decltype(t.a, true) {
        return true;
    }

    static auto has_accessible_a(...) -> bool {
        return false;
    }

    template <typename T>
    static auto has_accessible_b(const T &t) -> decltype(t.b, true) {
        return true;
    }

    static auto has_accessible_b(...) -> bool {
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

#ifdef TASK_01_INCREMENT_PREFIX
TEST_CASE("Foo::operator++ prefix returns left-hand side by non-const reference"
) {
    Foo f1("a", 10);
    Foo f2 = ++f1;
    auto p1 = static_cast<std::pair<std::string, int>>(f1);
    auto p2 = static_cast<std::pair<std::string, int>>(f2);
    CHECK(p1.first == "a1");
    CHECK(p1.second == 11);
    CHECK(p2.first == "a1");
    CHECK(p2.second == 11);

    ++(++f1);
    p1 = static_cast<std::pair<std::string, int>>(f1);
    CHECK(p1.first == "a111");
    CHECK(p1.second == 13);
    CHECK(p2.first == "a1");
    CHECK(p2.second == 11);
}
#endif  // TASK_01_INCREMENT_PREFIX

#ifdef TASK_02_INCREMENT_POSTFIX
TEST_CASE("Foo::operator++ postfix returns left-hand side copy") {
    Foo f1("a", 10);
    Foo f2 = f1++;
    auto p1 = static_cast<std::pair<std::string, int>>(f1);
    auto p2 = static_cast<std::pair<std::string, int>>(f2);
    CHECK(p1.first == "a1");
    CHECK(p1.second == 11);
    CHECK(p2.first == "a");
    CHECK(p2.second == 10);
}
#endif  // TASK_02_INCREMENT_POSTFIX

#ifdef TASK_03_WRITE
TEST_CASE("Foo::operator<< writes to a stream") {
    Foo f1("abc", 10);
    Foo f2("def", 20);
    std::ostringstream s;
    s << ">" << f1 << f2 << "<";
    CHECK(s.str() == ">abc 10def 20<");
}
#endif  // TASK_03_WRITE

#ifdef TASK_04_READ
TEST_CASE("Foo::operator>> reads from a stream") {
    std::istringstream s(" abc  10\tde\n20 bad ");
    Foo f1(1);
    Foo f2(2);
    Foo f3(3);
    s >> f1 >> f2;
    CHECK(s);
    s >> f3;
    CHECK(!s);
    auto p1 = static_cast<std::pair<std::string, int>>(f1);
    auto p2 = static_cast<std::pair<std::string, int>>(f2);
    CHECK(p1.first == "abc");
    CHECK(p1.second == 10);
    CHECK(p2.first == "de");
    CHECK(p2.second == 20);
}
#endif  // TASK_04_READ
