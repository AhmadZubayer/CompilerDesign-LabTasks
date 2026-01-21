#include<iostream>
using namespace std;

bool isNumeric(string s) {
     for (int i = 0; i < s.length(); i++) {
            int a = (int)s[i];  
            if (48 <= a <= 57) {
                return false;
                break;
            } 
            return true;
        }
}

int main() {
    string s;
    cin >> s;
    if (isNumeric(s)) {
        cout << "numeric constant" << endl;
    }
    else {
        cout << "not numeric" << endl;
    }   
    return 0;
}