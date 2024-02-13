#include <algorithm>
#include <vector>
#include <Windows.h>
#include "Window.hpp"

/// @brief
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
