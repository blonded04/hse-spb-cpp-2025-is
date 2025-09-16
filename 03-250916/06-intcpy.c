#include <assert.h>
#include <string.h>

// intcpy:
// - copies integer array contents into buffer
// - arguments:
//   * src (source) - integer array to be copied 
//   * dst (destination) - buffer to copy into
//   * size - amount of integers to copy from src
// - return value: 
//   * pointer to contents of dst buffer
int *intcpy(/* TODO */ src, /* TODO */ dst, size_t size) {
    // TODO
}

#define BIG_ENOUGH_BUFFER_SIZE 1000

int main(void) {
    int buffer[BIG_ENOUGH_BUFFER_SIZE] = {0};
    
    int src1[] = {1, 2, 3, 4};
    int src2[20] = {0};
    int src3[12] = {12, 32, 324, 5534, 34, 26, 235325, 654, 567, 547, 456, 4};

    assert(memcmp(intcpy(src1, buffer, sizeof(src1) / sizeof(int)), src1, sizeof(src1)) == 0);
    assert(memcmp(intcpy(src2, buffer + sizeof(src1) / sizeof(int), sizeof(src2) / sizeof(int)), src2, sizeof(src2)) == 0);
    assert(memcmp(intcpy(src3, buffer + 100, sizeof(src3) / sizeof(int)), src3, sizeof(src3)) == 0);

    return 0;
}
