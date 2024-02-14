/*! @file Window.hpp */

/*! @class Window
    @brief Contains all the information about Windows' window
*/

/*! @fn Window(HWND window_handler_)
    @brief Create a Window object passing window handler object
    @param window_handler_
*/

/*! @fn HWND getWindowHandler()
    @brief Get Window's handler object
    @return Window's HWND object
*/

/*! @fn void moveWindow(const POINT2& current_mouse_position, const bool& is_first_click)
    @brief Change Window's position depending on current mouse position:
    Calls private "updateValues" method in order to update Window's size and position;
    If it is a first click, remembers distance between the mouse cursor and the window;
    Calculates new Window's position;
    Moves the window using "MoveWindow" from Windows.h.
    @param current_mouse_position current mouse position
    @param is_first_click is it the first click
*/

/*! @fn void updateValues()
    @brief Updates Window's width, height, x and y
*/
    
#include <iostream>
#include <Windows.h>
#include "POINT2.hpp"

class Window {
public:
    explicit Window(HWND window_handler_) {
        window_handler = window_handler_;
    }

    HWND getWindowHandler() {
        return window_handler;
    }
    
    void moveWindow(const POINT2& current_mouse_position, const bool& is_first_click) {
        updateValues();
        if (is_first_click) delta = current_mouse_position + position; // INVERT: delta = current_mouse_pos - position;
        position = POINT2(0, 0)-(current_mouse_position - delta); // INVERT: position = current_mouse_pos - delta;
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
