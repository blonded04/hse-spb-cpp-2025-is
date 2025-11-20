#include <assert.h>
#include <stdio.h>
#include <string.h>

struct Point {
    int x, y;
    char color;
};

int point_equals(const struct Point *lhs, const struct Point *rhs) {
    return lhs->x == rhs->x && lhs->y == rhs->y && lhs->color == rhs->color;
}

void write_to(const char *filename) {
    printf("write_to(%s)\n", filename);

    struct Point pts[] = {
        {0, 5, 'r'},
        {-30, 12345678, 'g'},
        {10, 13, 'y'},
    };

    FILE *f = fopen(filename, TODO); // TODO: open file in binary write mode
    assert(f);
    // TODO: write `pts` to `f` with a single command
    assert(f);
    fclose(f);
    printf("    Written: %zu\n", sizeof pts);
}

void read_from(const char *filename) {
    printf("read_from(%s)\n", filename);

    struct Point pts[3];
    FILE *f = fopen(filename, TODO); // TODO: open file in binary read mode
    assert(f);
    
    printf("    Reading: %zu\n", sizeof pts);
    // TODO: read `pts` from `f` with a single command
    assert(f);
    fclose(f);

    struct Point expected1 = {0, 5, 'r'};
    struct Point expected2 = {-30, 12345678, 'g'};
    struct Point expected3 = {10, 13, 'y'};
    assert(point_equals(&pts[0], &expected1));
    assert(point_equals(&pts[1], &expected2));
    assert(point_equals(&pts[2], &expected3));
    printf("    pts[2] = %d %d %c\n", pts[2].x, pts[2].y, pts[2].color);
}

int main() {
    write_to("02.bin");
    read_from("02.bin");
    read_from("02.mingw-w64-x86_64-gcc.bin");  // May fail if layout and int storage is incompatible.
    return 0;
}
