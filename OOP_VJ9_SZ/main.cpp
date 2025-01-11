#include "header.hpp"
#include <iostream>
#include <string>

int main() {
    int x = 10;
    int y = 20;
    std::cout << "manji broj je: " << mymin(x, y) << std::endl;

    std::string str1 = "jabuka";
    std::string str2 = "banana";
    std::cout << "manji string je: " << mymin(str1, str2) << std::endl;

    return 0;
}