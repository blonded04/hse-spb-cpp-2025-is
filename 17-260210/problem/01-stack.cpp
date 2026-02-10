#include "01-stack.hpp"  // TODO: implement 01-stack.hpp
#include <cassert>

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    assert(s.pop() == 30);
    assert(s.pop() == 20);
    s.push(15);
    assert(s.pop() == 15);
    assert(s.pop() == 10);
}
