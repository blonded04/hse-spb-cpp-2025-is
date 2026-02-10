#include <cassert>
#include <type_traits>

struct Point {
    int x, y;
    char color;
};

bool operator==(const Point &lhs, const Point &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.color == rhs.color;
}

static_assert(std::is_trivially_copyable_v<Point>);

void copy_bytes(char *dest, const char *source, int count) {  // std::memcpy
    for (int i = 0; i < count; i++) {
        dest[i] = source[i];
    }
}

int main() {
    Point a{123, 456, 'x'};
    Point b{400, 500, 'y'};
    copy_bytes(TODO, TODO, sizeof(Point));
    assert(b.x == 123);
    assert(b.y == 456);
    assert(b.color == 'x');
}
