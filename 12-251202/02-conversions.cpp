#include <type_traits>
#include "doctest.h"

#define HAS_TESTS
#include "02-conversions-foo.hpp"
#include "02-conversions-foo.hpp"

#define TASK_01_IMPLICIT_CONSTRUCTOR_TWO_ARGS
#define TASK_02_IMPLICIT_CONSTRUCTOR_ONE_TWO_ARG
#define TASK_03_EXPLICIT_CONSTRUCTOR
#define TASK_04_IMPLICIT_CONVERSION_TO_PAIR

#ifdef TASK_01_IMPLICIT_CONSTRUCTOR_TWO_ARGS
TEST_CASE("Foo has implicit constructor from two arguments") {
    Foo f1("hello1", 10);
    Foo f2{"hello2", 11};
    Foo f3 = {"hello3", 12};
    Foo("hello", 10);
    Foo{"hello", 10};

    CHECK(f1.a == "hello1");
    CHECK(f1.b == 10);
    CHECK(f2.a == "hello2");
    CHECK(f2.b == 11);
    CHECK(f3.a == "hello3");
    CHECK(f3.b == 12);
}
#endif  // TASK_01_IMPLICIT_CONSTRUCTOR_TWO_ARGS

#ifdef TASK_02_IMPLICIT_CONSTRUCTOR_ONE_TWO_ARG
TEST_CASE("Foo has implicit constructors from int and (int, string)") {
    Foo f1(10);
    Foo f2{11};
    Foo f3 = {12};
    Foo f4{13, "bar"};
    Foo f5 = {14, "baz"};
    Foo(10);
    Foo{10};

    CHECK(f1.a == "from int");
    CHECK(f1.b == 10);
    CHECK(f2.a == "from int");
    CHECK(f2.b == 11);
    CHECK(f3.a == "from int");
    CHECK(f3.b == 12);
    CHECK(f4.a == "bar");
    CHECK(f4.b == 13);
    CHECK(f5.a == "baz");
    CHECK(f5.b == 14);
}
#endif  // TASK_02_IMPLICIT_CONSTRUCTOR_ONE_TWO_ARG

#ifdef TASK_03_EXPLICIT_CONSTRUCTOR
TEST_CASE("Foo has explicit constructor from one string") {
    Foo f1("hello1");
    Foo f2{"hello2"};
    Foo("hello");
    Foo{"hello"};

    CHECK(f1.a == "hello1");
    CHECK(f1.b == -1);
    CHECK(f2.a == "hello2");
    CHECK(f2.b == -1);

    // Should not compile:
    // Foo f3 = {"hello"};
    CHECK_MESSAGE(
        (!std::is_convertible_v<std::string, Foo>),
        "Looks like Foo(std::string) is implicit, should be explicit"
    );
}
#endif  // TASK_03_EXPLICIT_CONSTRUCTOR

#ifdef TASK_04_IMPLICIT_CONVERSION_TO_PAIR
void check_foo_pair(
    const Foo &f,
    const std::string &expected_a,
    int expected_b
) {
    std::pair<std::string, int> p = f;
    CHECK(p.first == expected_a);
    CHECK(p.second == expected_b);
}

TEST_CASE("Foo is implicitly convertible to pair<std::string, int>") {
    Foo f1("hello1", 10);
    Foo f2("hello2", 11);

    std::pair<std::string, int> p1 = f1;
    CHECK(p1.first == "hello1");
    CHECK(p1.second == 10);

    check_foo_pair(f2, "hello2", 11);
}
#endif  // TASK_04_IMPLICIT_CONVERSION_TO_PAIR
