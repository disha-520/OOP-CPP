#include <iostream>              // Includes input-output library


// Defines the Account class
class Account {

private:                         // Private members of Account
    double balance;              // Stores the account balance

    // Declares Auditor as a friend class
    friend class Auditor;

public:                          // Public members of Account

    // Parameterized constructor of Account
    explicit Account(double initialBalance)
        : balance(initialBalance) {}  // Initializes balance
};                               // Ends Account class


// Defines the Auditor class
class Auditor {

public:                          // Public members of Auditor

    // Function to inspect an Account object
    void inspect(const Account& account) const {

        // Accesses the private balance of Account
        std::cout << "Account Balance: "
                  << account.balance << '\n';
    }
};                               // Ends Auditor class


// Main function where program execution starts
int main() {

    // Creates an Account object with balance 5000
    Account account(5000.0);

    // Creates an Auditor object
    Auditor auditor;

    // Calls inspect() to access Account's private data
    auditor.inspect(account);

    // Indicates successful program execution
    return 0;
}                               // Ends main function