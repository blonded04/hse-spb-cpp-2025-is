#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <type_traits>

struct Point {
    int x, y;
    char color;
};

bool operator==(const Point &lhs, const Point &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.color == rhs.color;
}

static_assert(std::is_trivially_copyable_v<Point>);

void write_to(const std::string &filename) {
    std::cout << "write_to(" << filename << ")" << std::endl;

    Point pts[] = {
        {0, 5, 'r'},
        {-30, 12'345'678, 'g'},
        {10, 13, 'y'},
    };

    std::ofstream f(filename, TODO);
    assert(f);
    // TODO: write `pts` to `f` with a single command.
    assert(f);
    std::cout << "    Written: " << sizeof pts << std::endl;
}

void read_from(const std::string &filename) {
    std::cout << "read_from(" << filename << ")" << std::endl;
    if (!std::filesystem::exists(filename)) {
        std::cout << "File " << filename << " does not exist.\n";
        std::cout << "Are you sure your current directory is correct? It is " << std::filesystem::current_path() << " at the moment.\n";
    }

    Point pts[3];

    std::ifstream f(filename, TODO);
    assert(f);

    std::cout << "    Reading: " << sizeof pts << std::endl;
    // TODO: read `pts` to `f` with a single command.
    assert(f);

    assert((pts[0] == Point{0, 5, 'r'}));
    assert((pts[1] == Point{-30, 12'345'678, 'g'}));
    assert((pts[2] == Point{10, 13, 'y'}));
    std::cout << "    pts[2] = " << pts[2].x << " " << pts[2].y << " " << pts[2].color << std::endl;
}

int main() {
    write_to("02.bin");
    read_from("02.bin");
    read_from("02.mingw-w64-x86_64-gcc.bin");  // May fail if layout and int storage is incompatible.
}
