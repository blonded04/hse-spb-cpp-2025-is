#include <cassert>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

struct read_error : std::runtime_error {
    read_error() : std::runtime_error("read error") {}
};

struct int_reader {
private:
    std::ifstream f;

public:
    int_reader(const std::string &name) : f(name) {
        if (!f) {
            throw read_error();
        }
    }

    int read() {
        int x;
        if (!(f >> x)) {
            throw read_error();
        }
        return x;
    }
};

int main() {
    try {
        std::cout << "Should print OK... ";
        {
            int_reader r("numbers.txt");
            assert(r.read() == 1);
            assert(r.read() == 23);
        }
        std::cout << "OK\n";
        std::cout << "Should fail... ";
        {
            int_reader r("does-not-exist.txt");
        }
    } catch (read_error &) {
        std::cout << "Unable to read\n";
        return 1;
    }
    return 0;
}
