#include "lab2.h"

void checkIdentifier() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    if (!((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z') || s[0] == '_')) {
        cout << "NOT IDENTIFIER" << endl;
        return;
    }
    
    for (int i = 1; i < s.length(); i++) {
        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_')) {
            cout << "NOT IDENTIFIER" << endl;
            return;
        }
    } 
    
    cout << "IDENTIFIER" << endl;
}