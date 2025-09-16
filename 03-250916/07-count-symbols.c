#include <assert.h>

// Try to implement this functions in two ways:
// * while-loop and don't use strlen function
// * for-loop and use strlen string.h function
unsigned count_symbols(/* TODO */) {
    // TODO
}

int main(void) {
    char str1[] = "missisipie";
    assert(count_symbols(str1, 's') == 3u);
    assert(count_symbols(str1, 'i') == 4u);
    assert(count_symbols(str1, 'm') == 1u);
    assert(count_symbols(str1, 'x') == 0u);
    assert(count_symbols(str1, 'z') == 0u);

    char str2[] = "abacaba";
    assert(count_symbols(str2, 'a') == 4u);
    assert(count_symbols(str2, 'b') == 2u);
    assert(count_symbols(str2, 'c') == 1u);
    assert(count_symbols(str2, '4') == 0u);
    assert(count_symbols(str2, ')') == 0u);

    char str3[] = "hello world\n!!$";
    assert(count_symbols(str3, 'l') == 3u);
    assert(count_symbols(str3, 'o') == 2u);
    assert(count_symbols(str3, '\n') == 1u);
    assert(count_symbols(str3, '$') == 1u);
    assert(count_symbols(str3, '!') == 2u);

    char str4[] = "somethingg\0is off\0for sure";
    assert(count_symbols(str4, 'g') == 2u);
    assert(count_symbols(str4, '0') == 0u);
    assert(count_symbols(str4, 's') == 1u);
    assert(count_symbols(str4, 'u') == 0u);
}
