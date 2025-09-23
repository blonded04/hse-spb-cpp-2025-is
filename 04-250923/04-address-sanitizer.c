#include <stdio.h>

int v[3] = {10, 20, 3};

int main() {
    int x = v[2];  // v[2] == 3, trying to confuse static analysis and compiler's warnings
    printf("%d\n", v[x]);  // UB
    printf("COMPLETED\n");
}
