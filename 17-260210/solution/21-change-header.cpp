#include <cassert>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <type_traits>

#pragma pack(push, 1)
struct Header {
    static inline constexpr std::uint16_t EXPECTED_MAGIC = 0x1234;
    std::uint16_t magic;
    std::int32_t a, b, c;
    std::uint16_t checksum;

    std::uint16_t expected_checksum() const {
        std::uint16_t result = 0;
        const unsigned char *data = reinterpret_cast<const unsigned char*>(this) + 2;
        // WARNING: do not try to reinterpret_cast `a` because `(char*)a + 5` is out of its storage and is UB.
        for (int i = 0; i < 12; i++) {
            result += data[i] * (i + 1);
        }
        return result;
    }
};
#pragma pack(pop)

static_assert(std::is_trivially_copyable_v<Header>);
static_assert(sizeof(Header) == 16);

int main(int argc, char *argv[]) {
    assert(argc == 3);

    Header hdr;
    {
        std::ifstream f(argv[1], std::ios_base::in | std::ios_base::binary);
        assert(f);
        f.read(reinterpret_cast<char*>(&hdr), sizeof hdr);
        assert(f);
    }
    assert(hdr.magic == Header::EXPECTED_MAGIC);
    assert(hdr.checksum == hdr.expected_checksum());
    std::cout << hdr.a << " " << hdr.b << " " << hdr.c << std::endl;
    {
        std::int32_t tmp = hdr.a;
        hdr.a = hdr.b;
        hdr.b = tmp;
    }
    hdr.c++;
    hdr.checksum = hdr.expected_checksum();
    {
        std::ofstream f(argv[2], std::ios_base::out | std::ios_base::binary);
        assert(f);
        f.write(reinterpret_cast<const char*>(&hdr), sizeof hdr);
        assert(f);
    }
}
