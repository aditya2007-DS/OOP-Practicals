/*Assignment 4
Student as Learner and Participant, multiple inheritance*/

#include <iostream>
using namespace std;

// Base Class 1
class Learner
{
public:
    void study()
    {
        cout << "Student attends classes and studies." << endl;
    }
};

// Base Class 2
class Participant
{
public:
    void joinEvent()
    {
        cout << "Student joins university clubs and events." << endl;
    }
};

// Derived Class
class Student : public Learner, public Participant
{
};

int main()
{
    Student s;

    s.study();
    s.joinEvent();

    return 0;
}

/*
Output:
Student attends classes and studies.
Student joins university clubs and events.
*/
