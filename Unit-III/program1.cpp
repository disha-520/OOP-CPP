#include <iostream>                 // Includes the input-output stream library

int add(int first, int second) {    // Defines add() function for two integers
    return first + second;          // Returns the sum of two integers
}

double add(double first, double second) { // Defines add() function for two doubles
    return first + second;               // Returns the sum of two double values
}

int add(int first, int second, int third) { // Defines add() function for three integers
    return first + second + third;          // Returns the sum of three integers
}

int main() {                            // Main function where program execution starts

    std::cout << "Sum of two integers: " // Displays a message
              << add(10, 20)             // Calls add() for two integers
              << '\n';                   // Moves output to the next line

    std::cout << "Sum of two doubles: "  // Displays a message
              << add(2.5, 3.7)           // Calls add() for two double values
              << '\n';                   // Moves output to the next line

    std::cout << "Sum of three integers: " // Displays a message
              << add(10, 20, 30)            // Calls add() for three integers
              << '\n';                      // Moves output to the next line

    return 0;                            // Returns 0 to indicate successful execution
}                                        // Ends the main() function