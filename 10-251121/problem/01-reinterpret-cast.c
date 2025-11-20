#include "assert.h"

struct Point {
    int x, y;
    char color;
};

void copy_bytes(char *dest, const char *source, int count) {  // std::memcpy
    for (int i = 0; i < count; i++) {
        dest[i] = source[i];
    }
}

int main() {
    struct Point a = (struct Point) {123, 456, 'x'};
    struct Point b = (struct Point){400, 500, 'y'};
    copy_bytes(TODO, TODO, sizeof(struct Point));
    assert(b.x == 123);
    assert(b.y == 456);
    assert(b.color == 'x');
}
