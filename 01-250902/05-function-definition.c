#include <assert.h>
#include <stdio.h>

int add(int lhs, int rhs)
{
    return lhs + rhs;
}

// Begin TODO {
TODO multiply(TODO)
{
    TODO
}

TODO increment(TODO)
{
    TODO
}
// } End TODO

int main(void)
{
    assert(increment(0) == 1);
    assert(increment(-1) == 0);
    assert(add(1, 2) == 3);
    assert(add(100, 73) == 173);
    assert(multiply(2, 3) == 6);
    assert(multiply(4, 7) == 28);
    assert(multiply(add(1, 2), add(6, 5)) == 33);
    assert(increment(multiply(add(1, 2), add(6, 5))) == 34);

    printf("All good!\n");
    return 0;
}
