#include <cassert>

// TODO: add class point

// #define TEST_POINT_CREATE
// #define TEST_POINT_ROTATE
// #define TEST_POINT_CONSTRUCTORS
// DISABLE ALL OTHER TESTS BEFORE TESTING TEST_POINT_ENCAPSULATION
// #define TEST_POINT_ENCAPSULATION

int main() {
#ifdef TEST_POINT_CREATE
    Point p = Point(1, 2);
    assert(p.x == 1 && p.y == 2);
    p.y = 3;
    assert(p.y == 3);
#endif  // TEST_POINT_CREATE

#ifdef TEST_POINT_ROTATE
    Point point = Point(3, 4);
    point.rotate90();
    assert(point.x == -4);
    assert(point.y == 3);
#endif  // TEST_POINT_ROTATE

#ifdef TEST_POINT_CONSTRUCTORS
    Point p1 = {1, 2}, p2(1), p3;
    assert(p1.x == 1 && p1.y == 2);
    assert(p2.x == 1 && p2.y == 0);
    assert(p3.x == 0 && p3.y == 0);
#endif  // TEST_POINT_CONSTRUCTORS

#ifdef TEST_POINT_ENCAPSULATION
    Point my_point(2, 3);
    assert(my_point.getX() == 2 && my_point.getY() == 3);
    my_point.moveX(-2);
    assert(my_point.getX() == 0);
    assert(my_point.getMoveCount() == 1);
#endif  // TEST_POINT_ENCAPSULATION
}
