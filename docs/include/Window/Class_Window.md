
---
 <h4 align="center"> Declared In The Following File: <a href="./Window.md"> ./include/Window.hpp </a></h4> 

---
# Window Class Reference
### Contains all the information about Windows' window

---
## Public Member Functions

|||
|-|-|
|  | <p> [Window::Window](./Class_Window.md#Window::Window(HWND_window_handler_)) (HWND window_handler_) </p> <p> Create a Window object passing window handler object </p> <img width=1920/> |
| HWND | <p> [Window::getWindowHandler](./Class_Window.md#HWND_Window::getWindowHandler()) () </p> <p> Get Window's handler object </p> <img width=1920/> |
| void | <p> [Window::moveWindow](./Class_Window.md#void_Window::moveWindow(const_POINT2&_current_mouse_position,_const_bool&_is_first_click)) (const POINT2& current_mouse_position, const bool& is_first_click) </p> <p> Change Window's position depending on current mouse position: </p> <img width=1920/> |

## Private Member Functions

|||
|-|-|
| void | <p> [Window::updateValues](./Class_Window.md#void_Window::updateValues()) () </p> <p> Updates Window's width, height, x and y </p> <img width=1920/> |


---
## Global Function Documentation


---
## Public Member Function Documentation

| <p id="Window::Window(HWND_window_handler_)"><p align="left"> `Window::Window(HWND window_handler_)` |
|-|
| <p> <p> Create a Window object passing window handler object </p><p> <b> Parameters: </b> </p> <ul> <li> <b> window_handler_ </b> </li> </ul> </p> <img width=1920/> | 

| <p id="HWND_Window::getWindowHandler()"><p align="left"> `HWND Window::getWindowHandler()` |
|-|
| <p> <p> Get Window's handler object </p><p> <b> Returns: </b> </p> <ul> <li> Window's HWND object </li> </ul> </p> <img width=1920/> | 

| <p id="void_Window::moveWindow(const_POINT2&_current_mouse_position,_const_bool&_is_first_click)"><p align="left"> `void Window::moveWindow(const POINT2& current_mouse_position, const bool& is_first_click)` |
|-|
| <p> <p> Change Window's position depending on current mouse position: </p><p> <b> Detailed description: </b> </p> <ul> <li> Calls private "updateValues" method in order to update Window's size and position; </li> <li> If it is a first click, remembers distance between the mouse cursor and the window; </li> <li> Calculates new Window's position; </li> <li> Moves the window using "MoveWindow" from Windows.h. </li> </ul><p> <b> Parameters: </b> </p> <ul> <li> <b> current_mouse_position </b> Current mouse position </li> <li> <b> is_first_click </b> Is it the first click </li> </ul> </p> <img width=1920/> | 

## Private Member Function Documentation

| <p id="void_Window::updateValues()"><p align="left"> `void Window::updateValues()` |
|-|
| <p> <p> Updates Window's width, height, x and y </p> </p> <img width=1920/> | 


## Private Member Data Documentation

| <p id="Window::width"><p align="left"> `Window::width` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="Window::height"><p align="left"> `Window::height` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="Window::window_handler"><p align="left"> `Window::window_handler` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="Window::window_rect"><p align="left"> `Window::window_rect` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="Window::delta"><p align="left"> `Window::delta` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="Window::position"><p align="left"> `Window::position` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 


The documentation for this class was generated using [MdDox](https://github.com/DangeL187/MdDox)
