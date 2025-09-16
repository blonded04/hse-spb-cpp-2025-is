#include <assert.h>
#include <stdlib.h>

int scalar_product(int *lhs, int *rhs, int size) {
    // TODO
}

int main(void) {
    int a1[] = {1, 2, 3, 4, 5};
    int b1[] = {1, 0, 1, 0, 1};
    int b2[] = {3, 2, 1, 9, 10};

    assert(scalar_product(a1, b1, sizeof(a1) / sizeof(int)) == 9);
    assert(scalar_product(b1, a1, sizeof(a1) / sizeof(int)) == 9);

    assert(scalar_product(a1, b2, sizeof(a1) / sizeof(int)) == 96);

    assert(scalar_product(NULL, NULL, 0) == 0);
}
