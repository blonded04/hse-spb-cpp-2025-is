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
    int_reader(const std::string &name) : f(name) {}

    bool is_open() {
        return f.is_open();
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
            // TODO: add 'file is always opened' to int_reader's invariant so the if below can be removed without altering program's behavior.
            if (!r.is_open()) {
                std::cout << "Unable to read\n";
                return 1;
            }
        }
    } catch (read_error &) {
        std::cout << "Unable to read\n";
        return 1;
    }
    return 0;
}
