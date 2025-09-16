// TODO fix functions swapInt and swapFloat:
// * functions must have return type void.
// * you can also edit its API and every call to either swapInt
//   and swapFloat. 

#include <assert.h>

void swapInt(int lhs, int rhs) {
    int tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

void swapFloat(float lhs, float rhs) {
    float tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

int main(void) {
    int x = 30, y = 50;
    float a = 1.5f, b = 2.4f;

    assert(x == 30 && y == 50);
    swapInt(x, y);
    assert(x == 50 && y == 30);

    assert(a == 1.5f && b == 2.4f);
    swapFloat(a, b);
    assert(a == 2.4f && b == 1.5f);

    return 0;
}
