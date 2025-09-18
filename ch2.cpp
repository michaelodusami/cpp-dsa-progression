// File: main.cpp
// Author: Grok, created by xAI
// Purpose: A comprehensive demonstration of C++ functions, file organization, namespaces,
//          and preprocessor directives. This file simulates a multi-file project in a single
//          file for simplicity, teaching core concepts from Chapter 2 of C++ basics.

// === Topic Overview ===
// This program covers:
// - Functions: Value-returning, void, parameters, local scope, forward declarations.
// - File Organization: Simulated header files, header guards, and multiple file structure.
// - Namespaces: Avoiding naming collisions.
// - Preprocessor: Directives for conditional compilation and header inclusion.
// - Program Design: Modular structure with utility functions for common tasks.

// === Significance in Computer Science ===
// Functions are essential for modularity, allowing reusable and maintainable code.
// File organization and namespaces enable scalable programs by managing complexity and
// preventing naming conflicts. These concepts are critical for large-scale software development.

// === Simulated Header File: math_utils.hpp ===
#ifndef MATH_UTILS_HPP
#define MATH_UTILS_HPP

// Namespace to avoid naming collisions
namespace MathUtils {
// Forward declarations
double calculateAverage(double arr[], int size);
int factorial(int n);
bool isPrime(int n);
} // namespace MathUtils

#endif // MATH_UTILS_HPP

// === Simulated Header File: string_utils.hpp ===
#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <string>

namespace StringUtils {
// Forward declarations
std::string toUpperCase(const std::string& input);
void printGreeting(const std::string& name);
bool isPalindrome(const std::string& input);
} // namespace StringUtils

#endif // STRING_UTILS_HPP

// === Main Program ===
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

// === Preprocessor Directives ===
#define MAX_ARRAY_SIZE 100
#define DEBUG_MODE 1 // Enable debug output

// === Function Definitions: MathUtils ===
namespace MathUtils {
// Calculate the average of an array of doubles
double calculateAverage(double arr[], int size) {
    if (size <= 0) {
        std::cerr << "Error: Invalid array size\n";
        return 0.0;
    }
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

// Calculate factorial recursively
int factorial(int n) {
    if (n < 0) {
        std::cerr << "Error: Negative input for factorial\n";
        return -1;
    }
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// Check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
} // namespace MathUtils

// === Function Definitions: StringUtils ===
namespace StringUtils {
// Convert string to uppercase
std::string toUpperCase(const std::string& input) {
    std::string result = input;
    for (char& c : result) {
        c = std::toupper(c);
    }
    return result;
}

// Void function to print a greeting
void printGreeting(const std::string& name) {
    std::cout << "Hello, " << name << "!\n";
}

// Check if a string is a palindrome
bool isPalindrome(const std::string& input) {
    int left = 0;
    int right = input.length() - 1;
    while (left < right) {
        if (std::tolower(input[left]) != std::tolower(input[right])) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}
} // namespace StringUtils

// === Utility Functions ===
// Function with default parameter
void printArray(double arr[], int size, std::string label = "Array") {
    std::cout << label << ": ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// Function demonstrating pass-by-reference
void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function demonstrating pass-by-pointer
void incrementByPointer(int* value) {
    if (value != nullptr) {
        (*value)++;
    } else {
        std::cerr << "Error: Null pointer in incrementByPointer\n";
    }
}

// === Program Design: Main Function ===
int main() {
    // Demonstrate local scope
    {
        int localVar = 42;
        std::cout << "Local variable in main: " << localVar << "\n";
    }
    // localVar is out of scope here

    // Demonstrate MathUtils functions
    double numbers[MAX_ARRAY_SIZE] = {1.5, 2.5, 3.5, 4.5, 5.5};
    int size = 5;
    printArray(numbers, size, "Input Numbers");
    double avg = MathUtils::calculateAverage(numbers, size);
    std::cout << "Average: " << avg << "\n";

    int n = 5;
    int fact = MathUtils::factorial(n);
    std::cout << "Factorial of " << n << ": " << fact << "\n";

    int numToCheck = 17;
    bool prime = MathUtils::isPrime(numToCheck);
    std::cout << numToCheck << (prime ? " is prime" : " is not prime") << "\n";

    // Demonstrate StringUtils functions
    std::string testStr = "Hello";
    std::string upperStr = StringUtils::toUpperCase(testStr);
    std::cout << "Uppercase of \"" << testStr << "\": " << upperStr << "\n";

    StringUtils::printGreeting("Alice");

    std::string palindromeStr = "radar";
    bool isPal = StringUtils::isPalindrome(palindromeStr);
    std::cout << "\"" << palindromeStr << "\"" << (isPal ? " is a palindrome" : " is not a palindrome") << "\n";

    // Demonstrate pass-by-reference
    int x = 10, y = 20;
    std::cout << "Before swap: x = " << x << ", y = " << y << "\n";
    swapValues(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << "\n";

    // Demonstrate pass-by-pointer
    int value = 100;
    std::cout << "Before increment: value = " << value << "\n";
    incrementByPointer(&value);
    std::cout << "After increment: value = " << value << "\n";

    // Demonstrate preprocessor directive
#if DEBUG_MODE
    std::cout << "Debug mode is enabled.\n";
#endif

    return 0;
}

// === Additional Utility Functions ===
// Function to validate input range
bool isInRange(int value, int min, int max) {
    return value >= min && value <= max;
}

// Function to compute power iteratively
double power(double base, int exponent) {
    if (exponent < 0) {
        std::cerr << "Error: Negative exponent not supported\n";
        return 0.0;
    }
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

// Function to reverse an array in-place
void reverseArray(double arr[], int size) {
    if (size <= 0) {
        std::cerr << "Error: Invalid array size\n";
        return;
    }
    int left = 0;
    int right = size - 1;
    while (left < right) {
        double temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        ++left;
        --right;
    }
}

// Function to find the maximum element in an array
double findMax(double arr[], int size) {
    if (size <= 0) {
        std::cerr << "Error: Invalid array size\n";
        return 0.0;
    }
    double maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        maxVal = std::max(maxVal, arr[i]);
    }
    return maxVal;
}

// Function to count occurrences of a value in an array
int countOccurrences(double arr[], int size, double target) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            ++count;
        }
    }
    return count;
}

// Function to demonstrate function overloading
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

// Function to demonstrate default arguments
void printMessage(const std::string& message, int times = 1) {
    for (int i = 0; i < times; ++i) {
        std::cout << message << "\n";
    }
}

// Function to demonstrate recursive sum
int recursiveSum(int arr[], int size) {
    if (size <= 0) return 0;
    return arr[0] + recursiveSum(arr + 1, size - 1);
}

// Function to demonstrate pointer arithmetic
void printMemoryAddresses(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Address of arr[" << i << "]: " << &arr[i] << "\n";
    }
}

// === Simulated Additional Header: utils.hpp ===
#ifndef UTILS_HPP
#define UTILS_HPP

namespace Utils {
// Forward declarations for additional utility functions
bool isInRange(int value, int min, int max);
double power(double base, int exponent);
void reverseArray(double arr[], int size);
double findMax(double arr[], int size);
int countOccurrences(double arr[], int size, double target);
int add(int a, int b);
double add(double a, double b);
void printMessage(const std::string& message, int times);
int recursiveSum(int arr[], int size);
void printMemoryAddresses(int arr[], int size);
} // namespace Utils

#endif // UTILS_HPP

// === Program Design Notes ===
// This program is structured to mimic a multi-file project:
// - "Header files" are simulated with #ifndef guards.
// - Namespaces (MathUtils, StringUtils, Utils) group related functions.
// - Functions demonstrate various parameter passing mechanisms (value, reference, pointer).
// - Preprocessor directives (#define, #if) control compilation behavior.
// - The main function serves as a test driver to demonstrate all functionality.

// === How to Extend This Program ===
// 1. Split into actual .hpp and .cpp files for a real multi-file project.
// 2. Add more functions to handle specific tasks (e.g., file I/O, data validation).
// 3. Introduce classes to encapsulate related functions and data.
// 4. Use templates for generic programming.
// 5. Add error handling with exceptions for robustness.

// === End of File ===