#include <Windows.h>
#include "POINT2.hpp"

/// @brief Represents object containing all the information about Windows' window
class Window {
public:
    explicit Window(HWND window_handler_) {
        window_handler = window_handler_;
    }
    HWND getWindowHandler() {
        return window_handler;
    }
    void moveWindow(POINT2 current_mouse_pos, bool is_first_click) {
        updateValues();
        if (is_first_click) delta = current_mouse_pos - position;
        position = current_mouse_pos - delta;
        MoveWindow(window_handler, position.x, position.y, width, height, TRUE);
    }
private:
    int    width = 0, height = 0;
    HWND   window_handler;
    RECT   window_rect{};
    POINT2 delta;
    POINT2 position;

    void updateValues() {
        GetWindowRect(window_handler, &window_rect);
        width = window_rect.right - window_rect.left;
        height = window_rect.bottom - window_rect.top;
        position = POINT2(window_rect.left, window_rect.top);
    }
};
