#include "../doctest.h"
#include <vector>

// TODO: compile with `doctest_main.o`
// TODO: break both tests below in multiple places and see what happens.

TEST_CASE("Arithmetic works") {
    CHECK(2 * 3 == 6);
    CHECK(2 + 3 == 5);
    CHECK(2 - 3 == -1);
    CHECK(2 / 3 == 0);
}

TEST_CASE("vector::emplace_back") {
    std::vector<int> v{1, 2, 3};

    v.emplace_back(10);
    v.emplace_back(20);
    v.emplace_back(30);

    // CHECK is smarter than assert, no need in (()).
    CHECK(v == std::vector{1, 2, 3, 10, 20, 30});
}
