#include <assert.h>

void call_twice(TODO) {  // TODO: only function pointers
    f();
    f();
}

int x;

void increment_x() {
    x++;
}

int main() {
    call_twice(increment_x);
    assert(x == 2);
    call_twice(increment_x);
    x++;
    assert(x == 5);
}