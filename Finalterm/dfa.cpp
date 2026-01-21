#include <iostream>
using namespace std;

bool dfaVerify(string s) {
    int q[] = {0, 1, 2, 3, 4};
    int finalStates[] = {3, 4};
    int deathState[] = {};
    
    int currentState = 0;
    
    for(int i = 0; i < s.length(); i++) {
        char input = s[i];
        
        if(input != 'a' && input != 'b') {
            return false;
        }
        
        switch(currentState) {
            case 0:
                if(input == 'a') {
                    currentState = 3;
                } else if(input == 'b') {
                    currentState = 1;
                }
                break;
            
            case 1:
                if(input == 'a') {
                    currentState = 2;
                } else if(input == 'b') {
                    currentState = 1;
                }
                break;
            
            case 2:
                if(input == 'a') {
                    currentState = 3;
                } else if(input == 'b') {
                    currentState = 1;
                }
                break;
            
            case 3:
                if(input == 'a') {
                    currentState = 4;
                } else if(input == 'b') {
                    currentState = 1;
                }
                break;
            
            case 4:
                if(input == 'a') {
                    currentState = 4;
                } else if(input == 'b') {
                    currentState = 1;
                }
                break;
        }
    }
    
    for(int i = 0; i < 2; i++) {
        if(currentState == finalStates[i]) {
            return true;
        }
    }
    
    return false;
}

int main() {
    string s;
    cout << "RE= (ba)*b*a[a+ba(a+b)]*" << endl;
    
    while(true) {
        cout << "----------------" << endl;
        cout << "Enter a String:" << endl;
        cin >> s;
        
        if(dfaVerify(s)) {
            cout << "ACCEPTED :)" << endl;
        } else {
            cout << "REJECTED :(" << endl;
        }
    }
}