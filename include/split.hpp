/*! @fn std::vector<std::string> split(std::string line, char sym)
    @brief An analog of the split function from python
    @param line Line to split
    @param sym Separator
    @return std::vector<std::string> object
*/

#include <vector>
#include <string>

std::vector<std::string> split(std::string line, char sym) {
    std::vector<std::string> vec;
    std::string line2;
    for (unsigned int i = 0; i <= line.length(); i++) {
        if (line[i] != sym && i < line.length()) {
            line2 += line[i];
		}
		if (line[i] == sym) {
	        vec.push_back(line2);
			line2 = "";
		}
		if (i == line.length()) {
            vec.push_back(line2);
			line2 = "";
		}
	}
    return vec;
}
