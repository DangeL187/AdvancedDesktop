#include <algorithm>
#include <vector>
#include <Windows.h>
#include "Window.hpp"

/// @brief
class WindowManager {
public:
    WindowManager() = default;

    void moveWindows() {
        GetCursorPos(&current_mouse_pos);
        if (GetAsyncKeyState(VK_MBUTTON) & 0x8000) {
            EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(this));
            for (auto& item: active_windows) {
                item.moveWindow(POINT2(current_mouse_pos), is_first_click);
            } if (is_first_click) is_first_click = false; //if there was a click
        } else {
            is_first_click = true;
            active_windows.clear();
        }
    }
private:
    std::vector<Window> active_windows;
    POINT               current_mouse_pos = POINT(0, 0);
    bool                is_first_click = true;

    bool contains(HWND& hwnd) {
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
};
