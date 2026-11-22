// 5. Develop an e-commerce application that supports multiple
// payment methods. The exact payment method is chosen at runtime.
// Apply Dynamic Binding to decide which pay() executes.

#include <iostream>
using namespace std;

// Parent Class
class Payment
{
public:
    // Virtual Function
    virtual void pay()
    {
        cout << "General Payment Method" << endl;
    }
};

// Child Class 1
class CreditCard : public Payment
{
public:
    void pay() override
    {
        cout << "Payment made using Credit Card" << endl;
    }
};

// Child Class 2
class UPI : public Payment
{
public:
    void pay() override
    {
        cout << "Payment made using UPI" << endl;
    }
};

// Child Class 3
class NetBanking : public Payment
{
public:
    void pay() override
    {
        cout << "Payment made using Net Banking" << endl;
    }
};

int main()
{
    Payment *payment;
    int choice;

    cout << "------ E-COMMERCE PAYMENT SYSTEM ------" << endl;
    cout << "1. Credit Card" << endl;
    cout << "2. UPI" << endl;
    cout << "3. Net Banking" << endl;
    cout << "Enter your choice : ";
    cin >> choice;

    if (choice == 1)
    {
        payment = new CreditCard();
    }
    else if (choice == 2)
    {
        payment = new UPI();
    }
    else if (choice == 3)
    {
        payment = new NetBanking();
    }
    else
    {
        cout << "Invalid Choice" << endl;
        return 0;
    }

    // Dynamic Binding
    payment->pay();

    delete payment;

    return 0;
}
