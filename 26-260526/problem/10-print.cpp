#include <cassert>
#include <iostream>
#include <sstream>

// TODO: implement print_all()

struct SNonmovable {
    int value;
    SNonmovable(int value_) : value(value_) {}
    SNonmovable(SNonmovable&&) = delete;
    friend std::ostream& operator<<(std::ostream &os, const SNonmovable &s) {
        return os << "|" << s.value << "|";
    }
};

int main() {
    {
        std::stringstream s;
        SNonmovable x(10);
        print_all(s, 1, 2.5, x);
        std::cout << s.str();
        assert(s.str() == "1\n2.5\n|10|\n");
    }
    {
        std::stringstream s;
        print_all(s);
        assert(s.str() == "");
    }
}
