#include <vector>

struct Point {
    int x, y;

    Point() noexcept : x(0), y(0) {}
    Point(int x_, int y_) noexcept : x(x_), y(y_) {}

    // These five methods would be implicitly generated, so you typically DO NOT WRITE THEM.
    // Here we need them just to indicate which are noexcept and which are not.
    Point(const Point &other) noexcept = default;
    Point(Point &&other) noexcept = default;
    Point &operator=(const Point &other) noexcept = default;
    Point &operator=(Point &&other) noexcept = default;
    ~Point() noexcept = default;
};

struct Points {
private:
    std::vector<Point> points;

public:
    Points() noexcept : points() {}
    Points(int n) : points(n) {}

    // These five methods would be implicitly generated, so you typically DO NOT WRITE THEM.
    // Here we need them just to indicate which are noexcept and which are not.
    Points(const Points &other) = default;
    Points(Points &&other) noexcept = default;
    Points &operator=(const Points &other) = default;
    Points &operator=(Points &&other) noexcept = default;
    ~Points() noexcept = default;

    Point back() noexcept {
        return points.back();
    }

    void push_back(Point p) {
        points.push_back(std::move(p));
    }
};

int main() {
}
