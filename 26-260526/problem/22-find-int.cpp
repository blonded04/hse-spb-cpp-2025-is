#include <cassert>
#include <iostream>

// TODO: implement find_int(...) which returns its first argument which is `int`.
// Hint: do not use `if`, use recursion instead of loops.

int main() {
    assert(find_int(1.0, 2, "3", 4) == 2);
    assert(find_int(2, "3", 4) == 2);
    assert(find_int("3", 4) == 4);
    std::cout << "OK\n";
}
