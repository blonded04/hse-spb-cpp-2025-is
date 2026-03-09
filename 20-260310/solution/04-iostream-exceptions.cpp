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
    is.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    try {
        int a, b;
        is >> a >> b;
        std::cout << a + b << "\n";
    } catch (std::ios_base::failure &) {
        std::cout << "Format error\n";
    }
}
