
---
 <h4 align="center"> Declared In The Following File: <a href="./WindowManager.md"> ./include/WindowManager.hpp </a></h4> 

---
# WindowManager Class Reference
### Manages, stores, and updates all window objects

---
## Public Member Functions

|||
|-|-|
|  | <p> [WindowManager::WindowManager](./Class_WindowManager.md#WindowManager::WindowManager(int_main_screen_width,_int_main_screen_height,_int_total_screen_width,_int_total_screen_height,_unsigned_int_button_trigger_id)) (int main_screen_width, int main_screen_height, int total_screen_width, int total_screen_height, unsigned int button_trigger_id) </p> <p> Create WindowManager object </p> <img width=1920/> |
| void | <p> [WindowManager::update](./Class_WindowManager.md#void_WindowManager::update(const_POINT2&_current_mouse_position)) (const POINT2& current_mouse_position) </p> <p> Updates the position of all windows, depending on the current mouse position </p> <img width=1920/> |

## Private Member Functions

|||
|-|-|
| bool | <p> [WindowManager::contains](./Class_WindowManager.md#bool_WindowManager::contains(const_HWND&_hwnd)) (const HWND& hwnd) </p> <p> Check whether the WindowManager contains a Window object </p> <img width=1920/> |


---
## Global Function Documentation


---
## Public Member Function Documentation

| <p id="WindowManager::WindowManager(int_main_screen_width,_int_main_screen_height,_int_total_screen_width,_int_total_screen_height,_unsigned_int_button_trigger_id)"><p align="left"> `WindowManager::WindowManager(int main_screen_width, int main_screen_height, int total_screen_width, int total_screen_height, unsigned int button_trigger_id)` |
|-|
| <p> <p> Create WindowManager object </p><p> <b> Parameters: </b> </p> <ul> <li> <b> main_screen_width </b> </li> <li> <b> main_screen_height </b> </li> <li> <b> total_screen_width </b> </li> <li> <b> total_screen_height </b> </li> <li> <b> button_trigger_id </b> </li> </ul> </p> <img width=1920/> | 

| <p id="void_WindowManager::update(const_POINT2&_current_mouse_position)"><p align="left"> `void WindowManager::update(const POINT2& current_mouse_position)` |
|-|
| <p> <p> Updates the position of all windows, depending on the current mouse position </p><p> <b> Detailed description: </b> </p> <ul> <li> If trigger button is pressed then sets new virtual screen position using WindowManager::setNewVirtualPosition; </li> <li> Then moves all the windows using WindowManager::moveWindows; </li> <li> If trigger button is not pressed clears a list of active windows. </li> </ul> </p> <img width=1920/> | 

## Private Member Function Documentation

| <p id="bool_WindowManager::contains(const_HWND&_hwnd)"><p align="left"> `bool WindowManager::contains(const HWND& hwnd)` |
|-|
| <p> <p> Check whether the WindowManager contains a Window object </p><p> <b> Parameters: </b> </p> <ul> <li> <b> hwnd </b> Const reference to the HWND object used for the definition is a window in the list of windows </li> </ul><p> <b> Returns: </b> </p> <ul> <li> <b> true </b> or <b> false </b> </li> </ul> </p> <img width=1920/> | 


## Public Member Data Documentation

| <p id="WindowManager::CALLBACK"><p align="left"> `WindowManager::CALLBACK` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

## Private Member Data Documentation

| <p id="WindowManager::active_windows"><p align="left"> `WindowManager::active_windows` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="WindowManager::button_trigger"><p align="left"> `WindowManager::button_trigger` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="WindowManager::is_first_click"><p align="left"> `WindowManager::is_first_click` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="WindowManager::old_mouse_position"><p align="left"> `WindowManager::old_mouse_position` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="WindowManager::main_screen_size"><p align="left"> `WindowManager::main_screen_size` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="WindowManager::total_screen_size"><p align="left"> `WindowManager::total_screen_size` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="WindowManager::virtual_position"><p align="left"> `WindowManager::virtual_position` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 


The documentation for this class was generated using [MdDox](https://github.com/DangeL187/MdDox)
