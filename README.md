# KCli

`CLI` I made because I was bored.

# Features

- say <message>: Prints a penguin with a speech bubble and the provided message.
- time [timezone]: Displays the current time, with an optional UTC offset.
- joke: Tells a random joke.
- calc <num1> <operator> <num2>: Performs basic arithmetic operations (addition, subtraction, multiplication (no support for exponents yet), division).
- clear: Clears the screen.
- about: Tells you about this CLI.

# Compilation and Usage

To use on your machine:

1. Install a C++ compiler (e.g., GCC or Clang).
2. Clone the repository:
  ``` git clone https://github.com/33kc/KCli.git```
3. Navigate to the project directory:
   ```cd KCli```
4. Compile the code (ensure you're using a C++11 or later compiler (this is because i'm working on a file management system which only works with C++17)):
  ``` g++ -std=c++17 -o kc kc.cpp```
5. Run the program:
  ``` ./kc <command> [args]```

# Commands

- say <message>: Prints a penguin with a speech bubble. Example:
  kc say "Hello, world!"
  
- time [timezone]: Displays the current time in UTC, or in a specified timezone (e.g., UTC+2 or UTC-5). Example:
  kc time
  kc time +2

- joke: Displays a random joke. Example:
  kc joke

- calc <num1> <operator> <num2>: Performs basic arithmetic operations. Example: (this is a bit broken btw)
  kc calc 5 + 3
  kc calc 10 / 2

- clear: Clears the terminal screen. Example:
  kc clear
  (i've made it automatically flag to your win_x, so if you're on win_32 it's cls, if you're on win_64 it's clear)

- about: Stuff about this CLI. Example:
  kc about


### made about of pure boredom, brought to you by kc
