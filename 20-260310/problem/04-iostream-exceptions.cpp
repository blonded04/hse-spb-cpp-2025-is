#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char *argv[]) {
    assert(argc == 2);
    std::filesystem::path filename(argv[1]);
    if (!std::filesystem::exists(filename)) {
        std::cout << "File " << filename << " does not exist.\n";
        std::cout << "Are you sure your current directory is correct? It is " << std::filesystem::current_path() << " at the moment.\n";
        return 1;
    }

    std::ifstream is(filename);
    // TODO: ensure file is read correctly by:
    // 1. Enabling exceptions on the file.
    // 2. Wrapping three lines below in try-block.
    // 3. Catching the I/O exception class and printing 'Format error'.
    // You can only add new lines before or after the next three. You cannot add anything in between.
    int a, b;
    is >> a >> b;
    std::cout << a + b << "\n";
}
