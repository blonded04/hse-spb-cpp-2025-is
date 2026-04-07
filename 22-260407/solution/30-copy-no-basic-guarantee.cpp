#include <vector>

struct Points {
private:
    std::vector<int> xs, ys;

public:
    Points(int n) : xs(n), ys(n) {}

    int size() const {
        return static_cast<int>(xs.size());
    }

    int get_x(int i) const {
        return xs[i];
    }

    int get_y(int i) const {
        return ys[i];
    }

    void set_point(int i, int x, int y) {
        xs[i] = x;
        ys[i] = y;
    }

    // Possibly better solution: vector<pair<int, int>>
    Points(const Points &) = default;
    Points(Points &&) = default;
    Points &operator=(const Points &other) {
        if (this != &other) {
            *this = Points(other);
        }
        return *this;
    }
    Points &operator=(Points &&) noexcept = default;
};

int main() {
    Points a(1'000'000);
    Points b(2'000'000);
    try {
        a = b;  // Copying of 'ys' throws, leaving 'xs' and 'ys' inconsistent.
    } catch (...) {
        if (a.size() > 0) {
            a.set_point(a.size() - 1, 0, 0);
        }
    }
}
