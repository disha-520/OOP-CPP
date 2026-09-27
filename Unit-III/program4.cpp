#include <iostream>                         // Includes the input-output stream library

class Counter {                             // Defines the Counter class

private:                                    // Declares private members
    int value;                              // Stores the counter value

public:                                     // Declares public members

    // Constructor to initialize the counter value
    explicit Counter(int initialValue = 0)
        : value(initialValue) {}

    // Overloads the prefix increment operator (++counter)
    Counter& operator++() {

        ++value;                            // Increments the value by 1

        return *this;                       // Returns the current object
    }

    // Overloads the postfix increment operator (counter++)
    Counter operator++(int) {

        Counter old = *this;                // Stores the old value

        ++value;                            // Increments the current value by 1

        return old;                         // Returns the old value
    }

    // Function to display the counter value
    void display() const {

        std::cout << value << '\n';         // Displays the value
    }
};                                          // Ends the Counter class

int main() {                                // Main function where execution starts

    Counter counter(5);                     // Creates a Counter object with value 5

    std::cout << "After prefix increment: "; // Displays prefix increment message

    ++counter;                              // Performs prefix increment

    counter.display();                      // Displays the updated value

    std::cout << "Value returned by postfix increment: "; // Displays postfix message

    Counter oldValue = counter++;           // Performs postfix increment and stores old value

    oldValue.display();                     // Displays the old value returned by postfix increment

    std::cout << "Counter after postfix increment: "; // Displays updated counter message

    counter.display();                      // Displays the counter's new value

    return 0;                               // Returns 0 for successful execution
}                                           // Ends the main() function