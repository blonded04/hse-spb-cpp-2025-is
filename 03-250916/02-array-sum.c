#include <assert.h>

int array_sum(/* TODO */) {
    // TODO
}

#define A_SIZE 7
#define B_SIZE 4

int main(void) {
    int a[A_SIZE] = {1, 2, 3, 4, 5, 6, 7};

    int b[B_SIZE] = {0};
    *(b + 2) = -1;
    *(b + 3) = 1;
    *(b + 1) = -2;

    assert(sizeof(a) == sizeof(int) * A_SIZE);
    assert(sum(a, 7) == 28);
    assert(sum(a, 3) == 6);
    assert(sum(a + 2, 2) == 7);
    assert(sum(b + 1, /* TODO */) == -3);
    assert(sum(b, /* TODO */) == -3);

    return 0;
}
