// File: cpp_basics.cpp
// Author: Grok, created by xAI
// hey guys.... on my right monitor, I have a file displaying some code to fully comphrehend the cpp language chapter 2 because I am a fan of practical application sooooo I will be typing it out and trying to understand things as I do.... I should also mention that I have learned C++, Python, Java, Javascript, and Typescript already but its been about 2 years since I have touched C++ so this is why I am doing this practical application instead of the original read through the docs method

// Description: This program serves as a comprehensive introduction to C++ basics, covering
// statements, program structure, comments, variables, initialization, input/output with iostream,
// uninitialized variables, keywords, identifiers, whitespace, literals, operators, expressions,
// and developing a first program. The code is designed to teach these concepts through a
// practical example, ensuring the user can understand and apply them to solve related problems.
// The program includes a simple interactive console application that demonstrates these concepts.

// C++ Basics
// -- general purpose language (performance and flexibility)
// Attributes of C++ Basics:
// - **Statements**: Individual instructions in a program, terminated by semicolons (;).
// - **Program Structure**: A C++ program typically includes a main() function, headers, and
//   namespaces, with execution starting at main().
// - **Comments**: Single-line (//) or multi-line (/* */) notes ignored by the compiler.
// - **Variables**: Named memory locations with specific types (e.g., int, double, string).
// - **Initialization**: Assigning a starting value to a variable to avoid undefined behavior.
// - **iostream**: Library for input (cin) and output (cout, endl) operations.
// - **Keywords**: Reserved words like int, double, if, while that cannot be used as identifiers.
// - **Identifiers**: Names for variables, functions, etc., following naming rules.
// - **Whitespace**: Spaces, tabs, and newlines that improve code readability.
// - **Literals**: Fixed values like 42, 3.14, or "hello" used in expressions.
// - **Operators**: Symbols like +, -, *, /, ==, && for computations and comparisons.
// - **Expressions**: Combinations of literals, variables, and operators that evaluate to a value.

// Functionality:
// This program implements a simple console application that:
// - Demonstrates program structure with a main() function and helper functions.
// - Uses variables of different types with proper initialization.
// - Handles user input/output with iostream.
// - Includes examples of literals, operators, and expressions.
// - Shows proper commenting, whitespace, and identifier naming.
// - Avoids uninitialized variables to prevent undefined behavior.
// - Provides utility functions for common tasks like input validation and calculations.

// Necessary Information/Functions:
// - Core operations: Variable declaration, initialization, input/output, basic arithmetic.
// - Utility functions: Input validation, string conversion, simple calculations.
// - Edge cases: Handling invalid input, checking for uninitialized variables.
// - Problem-solving mindset: Break problems into smaller steps (e.g., get input, validate,
//   process, output), choose appropriate types and operators, track state, and handle errors.

// How to Think About These Problems:
// - **Decomposition**: Break a problem into smaller tasks (e.g., input, processing, output).
// - **Type Selection**: Choose appropriate data types (int for counts, double for decimals).
// - **Input Validation**: Ensure user input is valid to avoid errors or undefined behavior.
// - **State Tracking**: Use variables to store and update program state.
// - **Edge Cases**: Consider scenarios like empty input, negative numbers, or invalid types.
// - **Readability**: Use clear comments, consistent whitespace, and meaningful identifiers.
// - **Testing**: Test code with different inputs to ensure robustness.

#include <iostream> // for input and output
#include <string> // for string tyoe so we do not have to use const char *
#include <limits> // for numeric limits to handle input validation
#include <cctype> // for char handling such as isdigit()

using namespace std;

// function declarations and prototypes
void displayWelcomeMessage();
int getValidIntegerInput(const std::string& prompt);
double getValidDoubleInput(const std::string& prompt);
std::string getValidStringInput(const std::string& prompt);
void clearInputBuffer();
bool isValidName(const std::string& name);

int main(){
    
    std::cout << "Starting the C++ Basics Demo Program\n" << std::endl;

    // 1.2 Comments
    // single
    /* multi line
    comments 
    */
    
    // introduction to objects and variables
    // variables are named memory locations with specific types
    int userAge = 0;
    double userHeight = 0.0;
    std::string userName = "";
    char userInitial = 'a';

    // 1.4 Variable Assignment and Initialization
    // Variables should always be initialized to avoid undefined behavior.
    // Using {} for uniform initialization (C++11 and later)

    int count{0};
    double pi{3.14};
    std::string greeting{"Hello"};

    displayWelcomeMessage();
    userName = getValidStringInput("Enter your name: ");
    userInitial = userName.empty() ? 'N' : userName[0];
    userAge = getValidIntegerInput("Enter your age: ");
    userHeight = getValidDoubleInput("Enter your height in meters: ");

    // Output collected information
    std::cout << "\nUser Information:" << std::endl;
    std::cout << "Name: " << userName << std::endl;
    std::cout << "Initial: " << userInitial << std::endl;
    std::cout << "Age: " << userAge << " years" << std::endl;
    std::cout << "Height: " << userHeight << " meters" << std::endl;

    return 0;
}

// Function to display a welcome message
void displayWelcomeMessage() {
    std::cout << "=====================================" << std::endl;
    std::cout << "Welcome to the C++ Basics Demo!" << std::endl;
    std::cout << "This program demonstrates fundamental C++ concepts." << std::endl;
    std::cout << "=====================================\n" << std::endl;
}
int getValidIntegerInput(const std::string& prompt) {
    int value;
    bool validInput = false;

    while (!validInput) {
        std::cout << prompt;
        if (std::cin >> value) {
            validInput = true;
        } else {
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            clearInputBuffer();
        }
    }
    return value;
}

std::string getValidStringInput(const std::string& prompt) {
    std::string input;
    bool validInput = false;

    while (!validInput) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (isValidName(input)){
            validInput = true;
        }
        else {
            std::cout << "Invalid name. Please use letters, spaces, or hyphens only." << std::endl;
        }
    }

    return input;
}

bool isValidName(const std::string& name){
    if (name.empty()) return false;
    for (char c: name) {
        if (!isalpha(c) && c != ' ' && c != '-'){
            return false;
        }
    }
    return true;
}


void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to get valid double input with error handling
double getValidDoubleInput(const string& prompt) {
    double value;
    bool validInput = false;

    while (!validInput) {
        cout << prompt;
        if (cin >> value) {
            validInput = true;
        } else {
            cout << "Invalid input. Please enter a number." << endl;
            clearInputBuffer();
        }
    }
    return value;
}