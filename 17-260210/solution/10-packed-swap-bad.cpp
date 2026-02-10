#include <algorithm>
#include <cassert>
#include <iostream>
#include <type_traits>

#pragma pack(push, 1)
struct Header {
    char color;
    int w, h;
};
#pragma pack(pop)

static_assert(std::is_trivially_copyable_v<Header>);
static_assert(sizeof(int) == 4);
static_assert(sizeof(Header) == 9);

int main() {
    Header hdr{'r', 100, 200};
    {
       int tmp = hdr.w;
       hdr.w = hdr.h;
       hdr.h = tmp;
    }
    assert(hdr.w == 200);
    assert(hdr.h == 100);
}
