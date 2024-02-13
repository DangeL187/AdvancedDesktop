#include <algorithm>
#include <fstream>
#include <memory>
#include "WindowManager.hpp"
#include "split.h"

class AdvancedDesktop {
public:
    AdvancedDesktop() {
        try {
            loadSettings();
        } catch (std::exception& e) {
            throw std::runtime_error(std::string("Failed to load settings: ") + e.what());
        }
        window_manager = std::make_shared<WindowManager>(main_screen_width,
                                                         main_screen_height,
                                                         total_screen_width,
                                                         total_screen_height,
                                                         button_trigger_id);
    }

    void run() {
        POINT current_mouse_position;
        while (true) {
            GetCursorPos(&current_mouse_position);
            window_manager->update(POINT2(current_mouse_position));
        }
    }
private:
    int main_screen_width = 1920, main_screen_height = 1080;
    int total_screen_width = 1920, total_screen_height = 1080;
    unsigned int button_trigger_id = 4;
    std::shared_ptr<WindowManager> window_manager;

    void loadSettings() {
        std::ifstream file;
        file.open("settings.txt");
        std::string line;
        while (getline(file, line)) {
            remove_if(line.begin(), line.end(), isspace);
            if (line[0] != '#' && !line.empty()) {
                line = split(line, '#')[0]; // line without comments
                std::vector<std::string> expression = split(line, '='); // the first element is variable, the second is value
                std::vector<std::string> value = split(expression[1], 'x');
                if (expression[0] == "MainScreenSize") {
                    main_screen_width = std::stoi(value[0]);
                    main_screen_height = std::stoi(value[1]);
                } else if (expression[0] == "TotalScreenSize") {
                    total_screen_width = std::stoi(value[0]);
                    total_screen_height = std::stoi(value[1]);
                } else if (expression[0] == "TriggerButton") {
                    button_trigger_id = std::stoul(expression[1], nullptr, 16);
                }
            }
        }
        file.close();
    }
};