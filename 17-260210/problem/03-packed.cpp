#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <type_traits>

// TODO: make this `struct` and its fields packed
struct Header {
    char color;
    int w, h;
};

static_assert(std::is_trivially_copyable_v<Header>);
static_assert(sizeof(int) == 4);
static_assert(sizeof(Header) == 9);

void write_to(const std::string &filename) {
    std::cout << "write_to(" << filename << ")" << std::endl;

    Header hdr{'z', 100, 239017};

    std::ofstream f(filename, std::ios_base::out | std::ios_base::binary);
    assert(f);
    f.write(reinterpret_cast<const char*>(&hdr), sizeof hdr);
    assert(f);
    std::cout << "    Written: " << sizeof hdr << std::endl;
}

void read_from(const std::string &filename) {
    std::cout << "read_from(" << filename << ")" << std::endl;
    if (!std::filesystem::exists(filename)) {
        std::cout << "File " << filename << " does not exist.\n";
        std::cout << "Are you sure your current directory is correct? It is " << std::filesystem::current_path() << " at the moment.\n";
    }

    Header hdr;

    std::ifstream f(filename, std::ios_base::in | std::ios_base::binary);
    assert(f);

    std::cout << "    Reading: " << sizeof hdr << std::endl;
    f.read(reinterpret_cast<char*>(&hdr), sizeof hdr);
    assert(f);

    assert(hdr.color == 'z');
    assert(hdr.w == 100);
    assert(hdr.h == 239017);
    std::cout << "    hdr = " << hdr.color << " " << hdr.w << " " << hdr.h << std::endl;
}

int main() {
    write_to("03.bin");
    read_from("03.bin");
    read_from("03.mingw-w64-x86_64-gcc.bin");  // May fail if layout and int storage is incompatible.
}
