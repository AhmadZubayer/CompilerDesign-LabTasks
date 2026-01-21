#include "lab2.h"

void createFullName() {
    string firstName, lastName;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName; 

    string fullName = firstName + " " + lastName;
    cout << "FULLNAME: " << fullName << endl;
}