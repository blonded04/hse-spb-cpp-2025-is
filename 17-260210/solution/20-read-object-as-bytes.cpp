#include <cassert>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <memory>
#include <type_traits>

#pragma pack(push, 1)
struct Point {
    std::uint32_t x{}, y{};
};
#pragma pack(pop)

int main() {
    char data[50];
    static_assert(sizeof(Point) == 8);
    static_assert(alignof(Point) == 1);
    static_assert(std::is_trivially_copyable_v<Point>);

    Point *a = new (&data[1]) Point;
    Point *b = new (&data[23]) Point;

    std::ifstream f("20-read-object-as-bytes.bin", std::ios_base::in | std::ios_base::binary);
    f.read(data, sizeof data);
    std::cout << std::hex;
    std::cout << "a = " << a->x << " " << a->y << std::endl;
    std::cout << "b = " << b->x << " " << b->y << std::endl;

    assert(a->x == 0x6f6c6c65);
    assert(a->y == 0x6c726f77);
    assert(b->x == 0x34686769);
    assert(b->y == 0x72676835);

    b->~Point();
    a->~Point();
}
