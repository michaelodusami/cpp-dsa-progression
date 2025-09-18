/**
 * @file fundamental_data_types.cpp
 * @brief Comprehensive implementation of fundamental data types in C++.
 * 
 * Topic: Fundamental Data Types
 * 
 * Fundamental data types in C++ are the basic types provided by the language to store
 * different kinds of data, such as integers, floating-point numbers, characters, and
 * booleans. They form the foundation for data manipulation and are critical for
 * understanding memory management, type safety, and efficient computation.
 * 
 * This program includes:
 * - Overview of fundamental data types: void, signed/unsigned integers, fixed-width
 *   integers, size_t, floating-point numbers, booleans, and characters.
 * - Use of the sizeof operator to determine object sizes.
 * - Demonstrations of type conversion using static_cast.
 * - Conditional logic with if statements.
 * - Utility functions to display type properties, handle conversions, and demonstrate
 *   common operations.
 * - Handling edge cases like integer overflow, floating-point precision, and invalid
 *   conversions.
 * 
 * Key Attributes:
 * - Type: Defines the kind of data (e.g., int, float, char).
 * - Size: Memory occupied, found using sizeof.
 * - Range: Minimum and maximum values a type can hold.
 * - Signedness: Whether negative values are supported (signed vs. unsigned).
 * - Precision: Significant digits for floating-point types.
 * 
 * Problem-Solving Mindset:
 * - Decompose problems to identify required data types.
 * - Select types based on range, precision, and memory needs.
 * - Track state to avoid overflow or precision issues.
 * - Handle edge cases (e.g., max/min values, invalid inputs).
 * - Use static_cast for safe type conversions.
 * 
 * This code is designed to be educational, comprehensive, and reusable for solving
 * problems involving fundamental data types.
 */

#include <iostream>
#include <cstdint> // For fixed-width integers
#include <limits>  // For numeric limits
#include <iomanip> // For floating-point formatting
#include <string>

// Function prototypes
void display_type_properties();
void demonstrate_void();
void demonstrate_signed_integers();
void demonstrate_unsigned_integers();
void demonstrate_fixed_width_integers();
void demonstrate_size_t();
void demonstrate_scientific_notation();
void demonstrate_floating_point();
void demonstrate_boolean();
void demonstrate_chars();
void demonstrate_if_statements();
void demonstrate_type_conversion();

// Utility functions
template <typename T>
void print_type_info(const std::string& type_name);
void check_integer_overflow();
void check_floating_point_precision();
bool is_valid_char(char c);
int safe_convert_to_int(double value);
char safe_convert_to_char(int value);

// Main function
int main() {
    std::cout << "=== Fundamental Data Types in C++ ===\n\n";

    // Demonstrate each topic
    display_type_properties();
    demonstrate_void();
    demonstrate_signed_integers();
    demonstrate_unsigned_integers();
    demonstrate_fixed_width_integers();
    demonstrate_size_t();
    demonstrate_scientific_notation();
    demonstrate_floating_point();
    demonstrate_boolean();
    demonstrate_chars();
    demonstrate_if_statements();
    demonstrate_type_conversion();

    return 0;
}

/**
 * @brief Displays properties of fundamental data types using sizeof and numeric_limits.
 */
void display_type_properties() {
    std::cout << "=== Type Properties ===\n";
    std::cout << "Sizeof operator returns size in bytes.\n";
    print_type_info<char>("char");
    print_type_info<signed int>("signed int");
    print_type_info<unsigned int>("unsigned int");
    print_type_info<int8_t>("int8_t");
    print_type_info<uint16_t>("uint16_t");
    print_type_info<size_t>("size_t");
    print_type_info<float>("float");
    print_type_info<double>("double");
    print_type_info<bool>("bool");
    std::cout << "\n";
}

/**
 * @brief Template function to print size and range of a given type.
 * @param type_name Name of the type for display.
 */
template <typename T>
void print_type_info(const std::string& type_name) {
    std::cout << "Type: " << type_name << "\n";
    std::cout << "  Size: " << sizeof(T) << " bytes\n";
    std::cout << "  Min: " << std::numeric_limits<T>::min() << "\n";
    std::cout << "  Max: " << std::numeric_limits<T>::max() << "\n";
}

/**
 * @brief Demonstrates the void type.
 */
void demonstrate_void() {
    std::cout << "=== Void Type ===\n";
    std::cout << "Void is used for functions that return no value or for generic pointers.\n";
    
    // Void function example
    void print_hello(); // Declaration
    print_hello();
    
    // Void pointer example
    int x = 42;
    void* void_ptr = &x;
    std::cout << "Void pointer points to address: " << void_ptr << "\n";
    std::cout << "Dereferencing requires casting: " << *(static_cast<int*>(void_ptr)) << "\n\n";
}

void print_hello() {
    std::cout << "Hello from a void function!\n";
}

/**
 * @brief Demonstrates signed integers.
 */
void demonstrate_signed_integers() {
    std::cout << "=== Signed Integers ===\n";
    std::cout << "Signed integers can represent positive and negative numbers.\n";
    
    int a = -42;
    int b = 100;
    std::cout << "Example: a = " << a << ", b = " << b << "\n";
    std::cout << "Sum: " << a + b << "\n";
    
    // Check for overflow
    check_integer_overflow();
    std::cout << "\n";
}

/**
 * @brief Demonstrates unsigned integers and why to avoid them.
 */
void demonstrate_unsigned_integers() {
    std::cout << "=== Unsigned Integers ===\n";
    std::cout << "Unsigned integers represent non-negative numbers but can lead to subtle bugs.\n";
    
    unsigned int x = 10;
    unsigned int y = 20;
    std::cout << "x = " << x << ", y = " << y << "\n";
    std::cout << "x - y = " << x - y << " (underflow wraps around)\n";
    std::cout << "Avoid unsigned types unless strictly necessary (e.g., bit manipulation).\n\n";
}

/**
 * @brief Demonstrates fixed-width integers and size_t.
 */
void demonstrate_fixed_width_integers() {
    std::cout << "=== Fixed-Width Integers ===\n";
    std::cout << "Fixed-width integers (e.g., int8_t, uint32_t) have guaranteed sizes.\n";
    
    int8_t small_num = 127;
    uint32_t large_num = 4294967295U;
    std::cout << "int8_t: " << static_cast<int>(small_num) << "\n";
    std::cout << "uint32_t: " << large_num << "\n\n";
}

/**
 * @brief Demonstrates size_t.
 */
void demonstrate_size_t() {
    std::cout << "=== size_t ===\n";
    std::cout << "size_t is an unsigned type for sizes and counts (e.g., array indices).\n";
    
    size_t array_size = 10;
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Array size: " << array_size << "\n";
    std::cout << "First element: " << arr[0] << ", Last element: " << arr[array_size - 1] << "\n\n";
}

/**
 * @brief Demonstrates scientific notation.
 */
void demonstrate_scientific_notation() {
    std::cout << "=== Scientific Notation ===\n";
    std::cout << "Scientific notation (e.g., 1.23e4) is used for floating-point literals.\n";
    
    double sci_num = 1.23e4; // 1.23 * 10^4
    std::cout << "Number: " << sci_num << "\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Fixed format: " << sci_num << "\n\n";
}

/**
 * @brief Demonstrates floating-point numbers.
 */
void demonstrate_floating_point() {
    std::cout << "=== Floating-Point Numbers ===\n";
    std::cout << "Float and double store decimal numbers with varying precision.\n";
    
    float f = 3.14159f;
    double d = 3.141592653589793;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "float: " << f << "\n";
    std::cout << "double: " << d << "\n";
    
    // Check precision issues
    check_floating_point_precision();
    std::cout << "\n";
}

/**
 * @brief Demonstrates boolean values.
 */
void demonstrate_boolean() {
    std::cout << "=== Boolean Values ===\n";
    std::cout << "bool represents true or false.\n";
    
    bool is_active = true;
    bool is_valid = false;
    std::cout << std::boolalpha; // Print true/false instead of 1/0
    std::cout << "is_active: " << is_active << "\n";
    std::cout << "is_valid: " << is_valid << "\n\n";
}

/**
 * @brief Demonstrates characters.
 */
void demonstrate_chars() {
    std::cout << "=== Characters ===\n";
    std::cout << "char stores single characters or small integers.\n";
    
    char c = 'A';
    char digit = '5';
    std::cout << "Character: " << c << "\n";
    std::cout << "Digit as char: " << digit << ", as int: " << static_cast<int>(digit) << "\n";
    
    // Validate character
    std::cout << "Is 'A' valid? " << (is_valid_char(c) ? "Yes" : "No") << "\n\n";
}

/**
 * @brief Demonstrates if statements.
 */
void demonstrate_if_statements() {
    std::cout << "=== If Statements ===\n";
    std::cout << "If statements use bool conditions for control flow.\n";
    
    int number = 42;
    if (number > 0) {
        std::cout << number << " is positive.\n";
    } else if (number < 0) {
        std::cout << number << " is negative.\n";
    } else {
        std::cout << number << " is zero.\n";
    }
    std::cout << "\n";
}

/**
 * @brief Demonstrates type conversion with static_cast.
 */
void demonstrate_type_conversion() {
    std::cout << "=== Type Conversion ===\n";
    std::cout << "static_cast ensures safe and explicit type conversions.\n";
    
    double d = 123.456;
    int i = static_cast<int>(d);
    std::cout << "double: " << d << ", converted to int: " << i << "\n";
    
    int num = 65;
    char c = static_cast<char>(num);
    std::cout << "int: " << num << ", converted to char: " << c << "\n";
    
    // Safe conversion examples
    double large_num = 1e9;
    int converted = safe_convert_to_int(large_num);
    std::cout << "Safe conversion of " << large_num << " to int: " << converted << "\n\n";
}

/**
 * @brief Checks for integer overflow.
 */
void check_integer_overflow() {
    std::cout << "Checking integer overflow...\n";
    int max_int = std::numeric_limits<int>::max();
    std::cout << "Max int: " << max_int << "\n";
    std::cout << "Max int + 1: " << max_int + 1 << " (overflow occurs)\n";
}

/**
 * @brief Checks floating-point precision issues.
 */
void check_floating_point_precision() {
    std::cout << "Checking floating-point precision...\n";
    float a = 1.0f / 3.0f;
    double b = 1.0 / 3.0;
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "float 1/3: " << a << "\n";
    std::cout << "double 1/3: " << b << "\n";
}

/**
 * @brief Validates if a character is printable.
 * @param c The character to check.
 * @return True if the character is printable, false otherwise.
 */
bool is_valid_char(char c) {
    return (c >= 32 && c <= 126); // ASCII printable range
}

/**
 * @brief Safely converts a double to an int, handling out-of-range values.
 * @param value The double to convert.
 * @return The converted int, or max/min int if out of range.
 */
int safe_convert_to_int(double value) {
    if (value > static_cast<double>(std::numeric_limits<int>::max())) {
        std::cout << "Warning: Value exceeds int max, returning max int.\n";
        return std::numeric_limits<int>::max();
    }

    // so to get the min or max of an int u have to do: std::numericlimits<int>::max()

    if (value < static_cast<double>(std::numeric_limits<int>::min())) {
        std::cout << "Warning: Value below int min, returning min int.\n";
        return std::numeric_limits<int>::min();
    }
    return static_cast<int>(value);
}

/**
 * @brief Safely converts an int to a char, handling invalid values.
 * @param value The int to convert.
 * @return The converted char, or '?' if invalid.
 */
char safe_convert_to_char(int value) {
    if (value >= 0 && value <= 127 && is_valid_char(static_cast<char>(value))) {
        return static_cast<char>(value);
    }
    std::cout << "Warning: Invalid char value, returning '?'.\n";
    return '?';
}