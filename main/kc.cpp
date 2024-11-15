#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <sstream>

void printPenguinWithSpeechBubble(const std::string& message)
{
    int messageLength = message.length();
    std::cout << "    __________" << std::endl;
    std::cout << "   / " << std::string(messageLength + 2, ' ') << " \\" << std::endl;
    std::cout << "  / " << message << " \\" << std::endl;
    std::cout << "   ----------" << std::endl;
    std::cout << "   .--." << std::endl;
    std::cout << "  |o_o |" << std::endl;
    std::cout << "  |:_/ |" << std::endl;
    std::cout << " //   \\ \\" << std::endl;
    std::cout << "(|     | )" << std::endl;
    std::cout << "/'\\_   _/`\\" << std::endl;
    std::cout << "   `---`" << std::endl;
}

void sayCommand(const std::vector<std::string>& args)
{
    if (args.size() > 1)
    {
        std::string message = "";
        for (size_t i = 1; i < args.size(); ++i)
        {
            message += args[i] + " ";
        }
        message = message.substr(0, message.length() - 1);
        printPenguinWithSpeechBubble(message);
    }
    else
    {
        std::cout << "Please provide a message after 'say'.\n";
    }
}

void timeCommand(const std::vector<std::string>& args)
{
    if (args.size() == 2)
    {
        std::time_t now = std::time(nullptr);
        char* dt = std::ctime(&now);
        std::cout << "Current UTC time: " << dt;
    }
    else if (args.size() == 3)
    {
        try
        {
            int timezoneOffset = std::stoi(args[2]);
            std::time_t now = std::time(nullptr);
            std::time_t adjustedTime = now + timezoneOffset * 3600;
            char* dt = std::ctime(&adjustedTime);
            std::cout << "Current time in UTC+" << timezoneOffset << ": " << dt;
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Invalid timezone offset. Please provide an integer.\n";
        }
    }
    else
    {
        std::cout << "Usage: time [timezone]\n";
        std::cout << "Timezone is the UTC offset (e.g., +2 for UTC+2, -5 for UTC-5).\n";
    }
}

void jokeCommand()
{
    const std::vector<std::string> jokes = {
        "Why don’t skeletons fight each other? They don’t have the guts.",
        "Why don't some couples go to the gym? Because some relationships don't work out.",
        "I told my wife she was drawing her eyebrows too high. She looked surprised.",
        "Why don't programmers like nature? It has too many bugs.",
        "Why was the math book sad? Because it had too many problems.",
        "I used to play piano by ear, but now I use my hands.",
        "What’s orange and sounds like a parrot? A carrot!",
        "What do you call fake spaghetti? An impasta.",
        "Why don’t eggs tell each other secrets? Because they might crack up.",
        "Why did the coffee file a police report? It got mugged."
    };
    std::srand(std::time(0));
    int randomIndex = std::rand() % jokes.size();
    std::cout << jokes[randomIndex] << std::endl;
}

void calcCommand(const std::vector<std::string>& args)
{
    if (args.size() != 4)
    {
        std::cout << "Usage: calc <num1> <operator> <num2>\n"; // bruh this part is a bit confusing to code
        return;
    }

    try
    {
        double num1 = std::stod(args[1]);
        double num2 = std::stod(args[3]);
        std::string op = args[2];

        if (op == "+")
        {
            std::cout << num1 + num2 << std::endl;
        }
        else if (op == "-")
        {
            std::cout << num1 - num2 << std::endl;
        }
        else if (op == "*")
        {
            std::cout << num1 * num2 << std::endl;
        }
        else if (op == "/")
        {
            if (num2 != 0)
            {
                std::cout << num1 / num2 << std::endl;
            }
            else
            {
                std::cout << "Error: Division by zero.\n";
            }
        }
        else
        {
            std::cout << "Invalid operator. Use +, -, *, or /.\n";
        }
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Invalid numbers. Please provide valid numbers.\n";
    }
}

void clearCommand()
{
    #if defined(_WIN32) || defined(_WIN64)
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

void aboutCommand()
{
    std::cout << "KCli v.1.1\n this was made out of pure boredom\n brought to you by kc";
}

void helpCommand()
{
    std::cout << "Available Commands:\n";
    std::cout << "1. say <message> - Prints a penguin with a speech bubble\n";
    std::cout << "2. time [timezone] - Displays the current time, optional UTC offset\n";
    std::cout << "3. joke - Tells a random joke\n";
    std::cout << "4. calc <num1> <operator> <num2> - Performs basic arithmetic\n";
    std::cout << "5. clear - Clears the screen\n";
    std::cout << "6. about - Stuff about this CLI\n";
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: kc <command> [args]\n";
        return 1;
    }

    std::string command = argv[1];
    std::vector<std::string> args(argv, argv + argc);

    if (command == "say")
    {
        sayCommand(args);
    }
    else if (command == "time")
    {
        timeCommand(args);
    }
    else if (command == "joke")
    {
        jokeCommand();
    }
    else if (command == "calc")
    {
        calcCommand(args);
    }
    else if (command == "clear")
    {
        clearCommand();
    }
    else if (command == "about")
    {
        aboutCommand();
    }
    else if (command == "help")
    {
        helpCommand();
    }
    else
    {
        std::cout << "Unrecognized command: " << command << std::endl;
    }

    return 0;
}
