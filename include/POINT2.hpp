#include <Windows.h>

/// @brief Extended version of Windows.h POINT structure
struct POINT2 {
public:
    LONG x, y;

    /// @brief Create a POINT2 object, specifying the coordinates
    explicit POINT2(LONG x_ = 0, LONG y_ = 0) {
        x = x_;
        y = y_;
    }
    /// @brief Create a POINT2 object using POINT object
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
