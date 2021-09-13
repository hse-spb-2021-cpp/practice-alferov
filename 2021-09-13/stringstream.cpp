#include <iostream>
#include <sstream>

int main() {
    std::string s;
    std::getline(std::cin, s);
    // std::cin >> s;
    std::istringstream ss{s};
    std::string t;
    ss >> t;
    std::string check;
    if (ss >> check) {
        // invalid command:w

    }
}
