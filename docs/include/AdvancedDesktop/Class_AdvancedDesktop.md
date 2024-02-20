
---
 <h4 align="center"> Declared In The Following File: <a href="./AdvancedDesktop.md"> ./include/AdvancedDesktop.hpp </a></h4> 

---
# AdvancedDesktop Class Reference
### Main application class

---
## Public Member Functions

|||
|-|-|
|  | <p> [AdvancedDesktop::AdvancedDesktop](./Class_AdvancedDesktop.md#AdvancedDesktop::AdvancedDesktop()) () </p> <p> Loads settings, initializes WindowManager object. </p> <img width=1920/> |
| void | <p> [AdvancedDesktop::run](./Class_AdvancedDesktop.md#void_AdvancedDesktop::run()) () </p> <p> The main method used to run an endless update cycle. </p> <img width=1920/> |

## Private Member Functions

|||
|-|-|
| void | <p> [AdvancedDesktop::loadSettings](./Class_AdvancedDesktop.md#void_AdvancedDesktop::loadSettings()) () </p> <p> Loads settings from settings.txt in ~/bin folder </p> <img width=1920/> |


---
## Global Function Documentation


---
## Public Member Function Documentation

| <p id="AdvancedDesktop::AdvancedDesktop()"><p align="left"> `AdvancedDesktop::AdvancedDesktop()` |
|-|
| <p> <p> Loads settings, initializes WindowManager object. </p><p> <b> Detailed description: </b> </p> <ul> <li> Throws an exception if the settings could not be loaded. </li> </ul> </p> <img width=1920/> | 

| <p id="void_AdvancedDesktop::run()"><p align="left"> `void AdvancedDesktop::run()` |
|-|
| <p> <p> The main method used to run an endless update cycle. </p><p> <b> Detailed description: </b> </p> <ul> <li> Updates mouse position and calls WindowManager::update using mouse position as an argument. </li> </ul> </p> <img width=1920/> | 

## Private Member Function Documentation

| <p id="void_AdvancedDesktop::loadSettings()"><p align="left"> `void AdvancedDesktop::loadSettings()` |
|-|
| <p> <p> Loads settings from settings.txt in ~/bin folder </p><p> <b> Detailed description: </b> </p> <ul> <li> The file <b> settings.txt </b> allows you to adjust: </li> <li> <b> Width </b> and <b> height </b> of your main screen </li> <li> <b> Width </b> and <b> height </b> of all your screens in total </li> <li> <b> The button </b> used to move windows </li> </ul> </p> <img width=1920/> | 


## Private Member Data Documentation

| <p id="AdvancedDesktop::main_screen_width"><p align="left"> `AdvancedDesktop::main_screen_width` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="AdvancedDesktop::main_screen_height"><p align="left"> `AdvancedDesktop::main_screen_height` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="AdvancedDesktop::total_screen_width"><p align="left"> `AdvancedDesktop::total_screen_width` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="AdvancedDesktop::total_screen_height"><p align="left"> `AdvancedDesktop::total_screen_height` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="AdvancedDesktop::button_trigger_id"><p align="left"> `AdvancedDesktop::button_trigger_id` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 

| <p id="AdvancedDesktop::window_manager"><p align="left"> `AdvancedDesktop::window_manager` |
|-|
| <p> <p> - </p> </p> <img width=1920/> | 


The documentation for this class was generated using [MdDox](https://github.com/DangeL187/MdDox)
