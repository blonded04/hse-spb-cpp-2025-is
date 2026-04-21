#include "02-stack.h"  // TODO: update 02-stack.h so it handles move-only types
#include <cassert>
#include <memory>

std::unique_ptr<int> c(int x) {
    return std::make_unique<int>(x);
}

int main() {
    stack<std::unique_ptr<int>> s;
    s.push(c(10));
    s.push(c(20));
    s.push(c(30));
    assert(*s.pop() == 30);
    assert(*s.pop() == 20);
    s.push(c(15));
    assert(*s.pop() == 15);
    assert(*s.pop() == 10);
}
