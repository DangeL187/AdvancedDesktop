/*! @class WindowManager
    @brief Manages, stores, and updates all window objects
*/

/*! @fn WindowManager::WindowManager(int main_screen_width, int main_screen_height, int total_screen_width, int total_screen_height, unsigned int button_trigger_id)
    @brief Create WindowManager object
    @param main_screen_width
    @param main_screen_height
    @param total_screen_width
    @param total_screen_height
    @param button_trigger_id
*/

/*! @fn void WindowManager::update(const POINT2& current_mouse_position)
    @brief Updates the position of all windows, depending on the current mouse position
    @det If trigger button is pressed then sets new virtual screen position using WindowManager::setNewVirtualPosition;
    @det Then moves all the windows using WindowManager::moveWindows;
    @det If trigger button is not pressed clears a list of active windows.
*/

/*! @fn bool WindowManager::contains(const HWND& hwnd)
    @brief Check whether the WindowManager contains a Window object
    @param hwnd Const reference to the HWND object used for the definition is a window in the list of windows
    @return <b> true </b> or <b> false </b>
*/

/*! @fn static BOOL CALLBACK WindowManager::EnumWindowsProc(HWND hwnd, LPARAM lParam)
    @brief Recursively updates the list of Window objects
*/

/*! @fn void WindowManager::moveWindows(const POINT2& current_mouse_position)
    @brief Calls "Window::moveWindow" for each Window object in the Window list
    @param current_mouse_position Const reference to the current mouse position
*/

/*! @fn void WindowManager::setNewVirtualPosition(const POINT2& current_mouse_position)
    @brief Updates the position of the virtual screen, but in such a way as not to go beyond it
*/

#include <algorithm>
#include <vector>
#include <Windows.h>
#include "Window.hpp"

//If it was the first time user clicked the trigger button then delta is calculated showing the distance from the initial click point to the window position

class WindowManager {
public:
    WindowManager(int main_screen_width,
                  int main_screen_height,
                  int total_screen_width,
                  int total_screen_height,
                  unsigned int button_trigger_id) {
        main_screen_size = POINT2(main_screen_width, main_screen_height);
        total_screen_size = POINT2(total_screen_width, total_screen_height);
        button_trigger = button_trigger_id;
    }

    void update(const POINT2& current_mouse_position) {
        if (is_first_click) old_mouse_position = current_mouse_position;
        if (GetAsyncKeyState(button_trigger) & 0x8000) {
            setNewVirtualPosition(current_mouse_position);
            moveWindows(current_mouse_position);
            old_mouse_position = current_mouse_position;
            if (is_first_click) is_first_click = false; // if there was a click
        } else {
            is_first_click = true;
            active_windows.clear();
        }
    }
private:
    std::vector<Window> active_windows;
    int                 button_trigger;
    bool                is_first_click = true;
    POINT2              old_mouse_position;
    POINT2              main_screen_size;
    POINT2              total_screen_size;
    POINT2              virtual_position;

    bool contains(const HWND& hwnd) {
        for (auto& item: active_windows) {
            if (item.getWindowHandler() == hwnd) {
                return true;
            }
        }
        return false;
    }

    static BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
        if (IsWindowVisible(hwnd)) {
            auto* this_class = reinterpret_cast<WindowManager*>(lParam);
            if (!this_class->contains(hwnd)) {
                this_class->active_windows.emplace_back(hwnd);
            }
        }
        return TRUE;
    }

    void moveWindows(const POINT2& current_mouse_position) {
        EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(this));
        for (auto& item: active_windows) {
            item.moveWindow(current_mouse_position, is_first_click);
        }
    }

    void setNewVirtualPosition(const POINT2& current_mouse_position) {
        POINT2 new_virtual_position;
        new_virtual_position.x = virtual_position.x + (current_mouse_position.x - old_mouse_position.x);
        new_virtual_position.y = virtual_position.y + (current_mouse_position.y - old_mouse_position.y);
        bool is_inside_width = new_virtual_position.x >= 0 && new_virtual_position.x + main_screen_size.x <= total_screen_size.x;
        bool is_inside_height = new_virtual_position.y >= 0 && new_virtual_position.y + main_screen_size.y <= total_screen_size.y;
        if (is_inside_width && is_inside_height) {
            virtual_position = new_virtual_position;
        } else {
            is_first_click = true;
        }
    }
};
