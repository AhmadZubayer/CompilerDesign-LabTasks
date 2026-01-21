#include "lab2.h"

int main() {
    int choice = -1;
    
    while(choice != 0) {
        cout << "4. Problem 4 - Check Identifier" << endl;
        cout << "5. Problem 5 - Find Average Value" << endl;
        cout << "6. Problem 6 - Find Max and Min" << endl;
        cout << "7. Problem 7 - Create Full Name" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        
        switch(choice) {
            case 4:
                checkIdentifier();
                break;
            case 5:
                findAverage();
                break;
            case 6:
                findMaxMin();
                break;
            case 7:
                createFullName();
                break;
            case 0:
                break;
            default:
                cout << "Invalid " << endl;
        }
    }
    
    return 0;
}
