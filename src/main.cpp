#include <iostream>
#include "AdvancedDesktop.hpp"

int main() {
    try {
        AdvancedDesktop advanced_desktop;
        advanced_desktop.run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}