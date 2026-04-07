#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

struct matrix {
private:
    // May be better cache locality than vector<vector<int>>, but more code.
    int height, width;
    std::vector<int> data;

public:
    matrix(int height_, int width_)
        : height(height_), width(width_), data(height * width) {}

    int &element(int row, int col) {
        return data[row * width + col];
    }

    const int &element(int row, int col) const {
        return data[row * width + col];
    }
};

int main() {
    matrix a(2, 3);
    matrix b(3, 4);
    a.element(1, 2) = 10;
    b.element(1, 2) = 20;

    assert(a.element(1, 2) == 10);
    assert(std::as_const(a).element(1, 2) == 10);
    assert(b.element(1, 2) == 20);

    a = b;
    assert(a.element(1, 2) == 20);
    assert(std::as_const(a).element(1, 2) == 20);
    assert(a.element(1, 2) == 20);
}
