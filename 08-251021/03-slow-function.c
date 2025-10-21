#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000000

struct heavy_struct {
    int state;
    char big_buffer[BUFFER_SIZE];
};

// BEGIN TODO:
// do not change semantics of this function
int bad_function(struct heavy_struct heavy) {
    return heavy.state;
}
// END TODO

int main(void) {
    //  memset sets `3rd argument` bytes to `2nd argument` pointed to `1st argument` ponter
    // and returns `1st argument`: https://en.cppreference.com/w/c/string/byte/memset  
    struct heavy_struct* p = memset(malloc(sizeof(struct heavy_struct)), 0, sizeof(struct heavy_struct));

    long long sum_of_results = 0;
    for (int i = 0; i < 1000000; i++) {
// BEGIN TODO:
        int result = bad_function(*p);
// END TODO:
        p->state++;
        sum_of_results += (long long) result;
    }

    printf("%lld\n", sum_of_results);

    free(p);
}
