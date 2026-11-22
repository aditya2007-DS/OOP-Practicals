// 6. Design a banking application where InterestCalculator
// uses method overloading.

#include <iostream>
using namespace std;

class InterestCalculator
{
public:
    // 1. Calculate interest using principal, rate and time
    double calculateInterest(double principal, double rate, double time)
    {
        return (principal * rate * time) / 100;
    }

    // 2. Calculate interest using principal and rate
    // Default time = 1 year
    double calculateInterest(double principal, double rate)
    {
        return (principal * rate * 1) / 100;
    }

    // 3. Calculate interest using principal only
    // Default rate = 5% and time = 1 year
    double calculateInterest(double principal)
    {
        return (principal * 5 * 1) / 100;
    }
};

int main()
{
    InterestCalculator calculator;

    double interest1, interest2, interest3;

    // Calling method with 3 parameters
    interest1 = calculator.calculateInterest(10000, 5, 2);

    // Calling method with 2 parameters
    interest2 = calculator.calculateInterest(10000, 6);

    // Calling method with 1 parameter
    interest3 = calculator.calculateInterest(10000);

    cout << "Interest using Principal, Rate and Time: "
         << interest1 << endl;

    cout << "Interest using Principal and Rate: "
         << interest2 << endl;

    cout << "Interest using Principal only: "
         << interest3 << endl;

    return 0;
}
