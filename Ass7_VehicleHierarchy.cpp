// 7. Create C++ using multilevel inheritance
// to represent a vehicle hierarchy.

#include <iostream>
#include <string>
using namespace std;

// Base Class
class Vehicle
{
protected:
    string brand;
    string model;

public:
    // Constructor to initialize base class attributes
    Vehicle(string b, string m) : brand(b), model(m)
    {
    }

    void displayVehicle()
    {
        cout << "Brand: " << brand << "\nModel: " << model << endl;
    }
};

// Derived Class 1 (Inherits from Vehicle)
class Car : public Vehicle
{
protected:
    int seatingCapacity;
    string fuelType;

public:
    // Constructor initializes Vehicle attributes
    // using member initializer list
    Car(string b, string m, int seats, string fuel)
        : Vehicle(b, m), seatingCapacity(seats), fuelType(fuel)
    {
    }

    void displayCar()
    {
        displayVehicle(); // Accessing base class method

        cout << "Seating Capacity: " << seatingCapacity
             << " seats" << endl;

        cout << "Fuel Type: " << fuelType << endl;
    }
};

// Derived Class 2 (Inherits from Car - Multilevel Inheritance)
class ElectricCar : public Car
{
private:
    float batteryCapacity; // in kWh
    float chargingTime;    // in hours

public:
    // Constructor initializes Car (and indirectly Vehicle) attributes
    ElectricCar(string b, string m, int seats, string fuel,
                float battery, float time)
        : Car(b, m, seats, fuel),
          batteryCapacity(battery),
          chargingTime(time)
    {
    }

    void displayElectricCar()
    {
        cout << "=== Electric Car Specifications ===" << endl;

        displayCar(); // Accessing intermediate class method

        cout << "Battery Capacity: " << batteryCapacity
             << " kWh" << endl;

        cout << "Charging Time: " << chargingTime
             << " hours" << endl;
    }
};

int main()
{
    // Creating an object of the derived-most class
    ElectricCar myTesla("Tesla", "Model S Plaid", 5,
                        "Electric", 100.0, 1.5);

    // Displaying all inherited and specific properties
    myTesla.displayElectricCar();

    return 0;
}
