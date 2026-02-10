#include <cassert>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <type_traits>

struct Header {
    // TODO: describe a 16-bytes little-endian struct like this:
    // 2 bytes: MAGIC value (should be 0x1234)
    // 4 bytes each: A, B, C
    // 2 bytes: CHECKSUM
    // CHECKSUM is computed as 1*byte[0] + 2*byte[1] + 3*byte[2] + ... for all 12 bytes of A, B, C.
    //
    // Do not use int/short, use std::uint8_t/std::int8_t and similar things because you need exact size in bits/bytes.
};

int main(int argc, char *argv[]) {
    assert(argc == 3);

    Header hdr;
    // TODO: read `hdr` from `argv[1]`
    // TODO: assert that `hdr` is correct
    // TODO: print A, B, C like `1 2 -3`
    // TODO: swap A and B, increase C by 1
    // TODO: write `hdr` to `argv[2]`
}
