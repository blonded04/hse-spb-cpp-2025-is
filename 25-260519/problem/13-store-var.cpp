#include <cassert>
#include <iostream>

int main() {
    int a = 0, b = 0, c = 0, d = 0;

    TODO print_abc = [TODO]() {
        std::cout << a << " " << b << " " << c << "\n";
    };

    print_abc();  // 0 0 0
    a = 20;
    print_abc();  // 20 0 0
    b = 5;
    c = 10;
    print_abc();  // 20 5 10
    std::cout << "d=0=" << d << "\n";  // 0

    assert(sizeof(print_abc) == 3 * sizeof(int*));  // Assuming int& member is int*: https://stackoverflow.com/questions/26631169/why-does-sizeof-a-reference-type-give-you-the-sizeof-the-type
}
