#include <assert.h>
#include <stdio.h>
#include <string.h>

// TODO: make this `struct` and its fields packed
struct Header {
    char color;
    int w, h;
};

void write_to(const char *filename) {
    printf("write_to(%s)\n", filename);

    struct Header hdr = {'z', 100, 239017};

    FILE *f = fopen(filename, "wb");
    assert(f);
    // TODO: write `hdr` to `f` with a single command
    assert(f);
    fclose(f);
    printf("    Written: %zu\n", sizeof hdr);
}

void read_from(const char *filename) {
    printf("read_from(%s)\n", filename);
    
    FILE *test = fopen(filename, "rb");
    if (!test) {
        printf("File %s does not exist.\n", filename);
        printf("Are you sure your current directory is correct?\n");
        return;
    }
    fclose(test);

    struct Header hdr;
    FILE *f = fopen(filename, "rb");
    assert(f);
    
    printf("    Reading: %zu\n", sizeof hdr);
    // TODO: read `hdr` from `f` with a single command
    assert(f);
    fclose(f);

    assert(hdr.color == 'z');
    assert(hdr.w == 100);
    assert(hdr.h == 239017);
    printf("    hdr = %c %d %d\n", hdr.color, hdr.w, hdr.h);
}

int main() {
    write_to("03.bin");
    read_from("03.bin");
    read_from("03.mingw-w64-x86_64-gcc.bin");  // May fail if layout and int storage is incompatible.
    return 0;
}
