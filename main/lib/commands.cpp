#include "commands.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
void say(const std::string& message) 
{
    int width = message.size() + 4;
    std::cout << " ";
    for (int i = 0; i < width; ++i) std::cout << "_";
    std::cout << "\n";
    std::cout << "< " << message << " >\n";
    std::cout << " ";
    for (int i = 0; i < width; ++i) std::cout << "-";
    std::cout << "\n";
    std::cout << R"(
     \
      \
         .--.
        |o_o |
        |:_/ |
       //   \ \
      (|     | )
     /'\_   _/`\
     \___)=(___/
    )";
    std::cout << std::endl;
}

