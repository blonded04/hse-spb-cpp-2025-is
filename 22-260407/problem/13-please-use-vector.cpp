#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

// TODO: rewrite `struct matrix` so that it follows Rule of Zero, not Rule of Five.
// I.e. get rid of all special constructors and operators.
struct matrix {
private:
    int height, width;
    int *data;

public:
    matrix(int height_, int width_)
        : height(height_), width(width_), data(new int[height * width]) {}

    matrix(const matrix &other) : matrix(other.height, other.width) {
        std::copy(other.data, other.data + height * width, data);
    }

    matrix(matrix &&other) noexcept
        : height(std::exchange(other.height, 0))
        , width(std::exchange(other.width, 0))
        , data(std::exchange(other.data, nullptr)) {
    }

    matrix &operator=(const matrix &other) {
        if (this != &other) {
            *this = matrix(other);
        }
        return *this;
    }

    matrix &operator=(matrix &&other) noexcept {
        std::swap(height, other.height);
        std::swap(width, other.width);
        std::swap(data, other.data);
        return *this;
    }

    ~matrix() {
        delete[] data;
    }

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
