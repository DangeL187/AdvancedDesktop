#include <Windows.h>

struct POINT2 {
public:
    LONG x, y;

    explicit POINT2(LONG x_ = 0, LONG y_ = 0) {
        x = x_;
        y = y_;
    }
    explicit POINT2(POINT point) {
        x = point.x;
        y = point.y;
    }

    POINT2 operator+(const POINT2& other) const {
        return POINT2(x + other.x, y + other.y);
    }
    POINT2 operator+(const POINT& other) const {
        return POINT2(x + other.x, y + other.y);
    }
    POINT2 operator-(const POINT2& other) const {
        return POINT2(x - other.x, y - other.y);
    }
    POINT2 operator-(const POINT& other) const {
        return POINT2(x - other.x, y - other.y);
    }
};