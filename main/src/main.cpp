#include <iostream>
#include <string>
#include "../lib/commands.h"
// here we go!
int main(int argc, char* argv[]) 
{
    if (argc < 2) 
    {
        std::cout << "Please provide a command.\n";
        return 1;
    }

    std::string command = argv[1];
    if (command == "x") 
    {
    }

    return 0;
}
