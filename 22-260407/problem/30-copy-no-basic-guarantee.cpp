#include <vector>

// The struct below provides no basic exception guarantee.
// TODO: write an example in main() which theoretically demonstrates that: an operation which may throw and break invariants
// TODO: fix the struct
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
};

int main() {
    // Spoiler: https://stackoverflow.com/questions/13341456
}
