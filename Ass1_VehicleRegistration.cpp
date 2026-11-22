/* Assignment 1
Vehicle Registration*/
#include<iostream>
using namespace std;

class Vehicle {
private:
  string registrationNumber;
  string ownerName;
  string vehicleType;
  
public:
  Vehicle(string regNo, string owner, string type) {
    registrationNumber = regNo;
    ownerName = owner;
    vehicleType = type;
  }
  void display() {
    cout << "Vehicle Registration Details" << endl;
    cout << "Registration Number: " << registrationNumber << endl;
    cout << "Owner Name: " << ownerName << endl;
    cout << "Vehicle Type: " << vehicleType << endl;
  }
};

int main() {
  Vehicle v1("MH12AB1234", "Aditya Kamble", "Car");
  
  v1.display();
  
  Vehicle v2("MH12AK7890", "Barack Obama", "2 Wheeler");
  
  v2.display();
  
  return 0;
}
/*Output: 
Vehicle Registration Details
Registration Number: MH12AB1234
Owner Name: Aditya Kamble
Vehicle Type: Car
Vehicle Registration Details
Registration Number: MH12AK7890
Owner Name: Barack Obama
Vehicle Type: 2 Wheeler
*/
