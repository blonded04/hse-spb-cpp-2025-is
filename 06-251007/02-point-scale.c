#include <assert.h>
#include <stdio.h>

// TODO

int main(void) {
    struct Point p1;
    p1.x = 1;
    p1.y = -2;

    point_scale(&p1, -5);

    assert(p1.x == -5);
    assert(p1.y == 10);

    return 0;
}
