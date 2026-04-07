#include <vector>

// TODO: add 'noexcept' on all methods below which cannot throw. Do not modify anything else. Discuss afterwards.
struct Point {
    int x, y;

    Point() : x(0), y(0) {}
    Point(int x_, int y_) : x(x_), y(y_) {}

    // These five methods would be implicitly generated, so you typically DO NOT WRITE THEM.
    // Here we need them just to indicate which are and which are not.
    Point(const Point &other) = default;
    Point(Point &&other) = default;
    Point &operator=(const Point &other) = default;
    Point &operator=(Point &&other) = default;
    ~Point() = default;
};

struct Points {
private:
    std::vector<Point> points;

public:
    Points() : points() {}
    Points(int n) : points(n) {}

    // These five methods would be implicitly generated, so you typically DO NOT WRITE THEM.
    // Here we need them just to indicate which are and which are not.
    Points(const Points &other) = default;
    Points(Points &&other) = default;
    Points &operator=(const Points &other) = default;
    Points &operator=(Points &&other) = default;
    ~Points() = default;

    Point back() {
        return points.back();
    }

    void push_back(Point p) {
        points.push_back(std::move(p));
    }
};

int main() {
}
