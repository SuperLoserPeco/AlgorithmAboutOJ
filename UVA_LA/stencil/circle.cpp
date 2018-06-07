#include <cmath>

struct Point {
    double x;
    double y;
    Point (double x = 0, double y = 0): x(x), y(y) {}
};
typedef Point Vector;

struct Circle {
    Point c;
    double r;
    Circle(Point c, double r):c(c),r(r) {}
    Point point(double a) {
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }
};

int main() {
    return 0;
}