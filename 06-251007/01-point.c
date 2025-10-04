#include <assert.h>
#include <stdio.h>

// TODO

int main(void) {
    struct Point p1;
    p1.x = 1;
    p1.y = 2;

    struct Point p2 = (struct Point) {.x = -1 * p1.x, .y = p1.y / 2};

    assert(p2.x == -1);
    assert(p2.y == 1);

    printf("All OK\n");

    return 0;
}
