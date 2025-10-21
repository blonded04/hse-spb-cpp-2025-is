#include <stdio.h>

int main(void) {
    const char* filename1 = "05-input1.txt";
    const char* filename2 = "05-input2.txt";
    FILE* f1 = fopen(filename1, "r");
    FILE* f2 = fopen(filename2, "r");

    char s[11] = { 0 };

    int result = 0;
    // TODO BEGIN: 
    // 1. don't get an UB when reading string bigger than sizeof(s)
    // 2. check for EOF
    while (1) {
        fscanf(f1, "%s", s);
    // TODO END
        printf("%s\n", s);
        result++;
    }
    printf("%d\n", result);

    fclose(f2);
    fclose(f1);
    return 0;
}