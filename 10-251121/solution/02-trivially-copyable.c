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

    FILE *f = fopen(filename, "wb");
    assert(f);
    size_t written = fwrite(pts, sizeof(struct Point), 3, f);
    assert(written == 3);
    fclose(f);
    printf("    Written: %zu\n", sizeof pts);
}

void read_from(const char *filename) {
    printf("read_from(%s)\n", filename);

    struct Point pts[3];
    FILE *f = fopen(filename, "rb");
    assert(f);
    
    printf("    Reading: %zu\n", sizeof pts);
    size_t read = fread(pts, sizeof(struct Point), 3, f);
    assert(read == 3);
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
    read_from("02.mingw-w64-x86_64-gcc.bin");
    return 0;
}
