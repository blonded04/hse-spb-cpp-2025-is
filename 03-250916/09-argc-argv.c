#include <stdio.h>

int main(int argc, char** argv) {  // also possible: (int argc, char* argv[])
    printf("Got %d arguments:\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("%d. Argument is: \"%s\"\n", i + 1, argv[i]);
    }
    
    return 0;
}
