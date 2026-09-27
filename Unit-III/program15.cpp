#include <iostream>                         // Includes the input-output stream library
#include <string>                           // Includes the string library

class Payment {                             // Defines the abstract Payment class

public:                                     // Declares public members

    // Declares a pure virtual function for making payment
    virtual void pay(double amount) const = 0;

    // Defines a virtual destructor
    virtual ~Payment() = default;
};                                          // Ends the Payment class


class CardPayment : public Payment {        // Defines CardPayment class inheriting from Payment

public:                                     // Declares public members

    // Overrides the pay() function
    void pay(double amount) const override {

        // Displays the amount paid using card
        std::cout << "Paid Rs. " << amount
                  << " using card\n";
    }
};                                          // Ends the CardPayment class


class UpiPayment : public Payment {         // Defines UpiPayment class inheriting from Payment

public:                                     // Declares public members

    // Overrides the pay() function
    void pay(double amount) const override {

        // Displays the amount paid using UPI
        std::cout << "Paid Rs. " << amount
                  << " using UPI\n";
    }
};                                          // Ends the UpiPayment class


class NetBankingPayment : public Payment {  // Defines NetBankingPayment class inheriting from Payment

public:                                     // Declares public members

    // Overrides the pay() function
    void pay(double amount) const override {

        // Displays the amount paid using net banking
        std::cout << "Paid Rs. " << amount
                  << " using net banking\n";
    }
};                                          // Ends the NetBankingPayment class


// Function to process payment using a Payment reference
void processPayment(const Payment& payment, double amount) {

    // Calls the appropriate pay() function
    payment.pay(amount);
}


int main() {                                // Main function where execution starts

    // Creates a CardPayment object
    CardPayment card;

    // Creates a UpiPayment object
    UpiPayment upi;

    // Creates a NetBankingPayment object
    NetBankingPayment netBanking;

    // Processes card payment of Rs. 1250
    processPayment(card, 1250.0);

    // Processes UPI payment of Rs. 750
    processPayment(upi, 750.0);

    // Processes net banking payment of Rs. 500
    processPayment(netBanking, 500.0);

    return 0;                               // Returns 0 for successful execution
}                                           // Ends the main() function