#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int str_comp(void *a, void *b) {
    (char*)a
    return TODO;  // Hint: use strcmp from standard library
}

int main() {
    const char *data[] = {
        "hello",
        "world",
        "meow",
        "abcd",
    };
    qsort(data, TODO, TODO, str_comp);
    // TODO: why following assertions don't simply test `data[0] == "abcd"`?
    assert(strcmp(data[0], "abcd") == 0);
    assert(strcmp(data[1], "hello") == 0);
    assert(strcmp(data[2], "meow") == 0);
    assert(strcmp(data[3], "world") == 0);
    printf("OK\n");
}
