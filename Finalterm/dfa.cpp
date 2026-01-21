#include <iostream>
using namespace std;

bool dfaVerify(string s) {
    char q[] = {'A', 'B', 'C', 'D', 'E'};
    char finalStates[] = {'D', 'E'};
    char deathState[] = {};
    
    char currentState = 'A';
    
    for(int i = 0; i < s.length(); i++) {
        char input = s[i];
        
        if(input != 'a' && input != 'b') {
            return false;
        }
        
        switch(currentState) {
            case 'A':
                if(input == 'a') {
                    currentState = 'D';
                } else if(input == 'b') {
                    currentState = 'B';
                }
                break;
            
            case 'B':
                if(input == 'a') {
                    currentState = 'C';
                } else if(input == 'b') {
                    currentState = 'B';
                }
                break;
            
            case 'C':
                if(input == 'a') {
                    currentState = 'D';
                } else if(input == 'b') {
                    currentState = 'B';
                }
                break;
            
            case 'D':
                if(input == 'a') {
                    currentState = 'E';
                } else if(input == 'b') {
                    currentState = 'B';
                }
                break;
            
            case 'E':
                if(input == 'a') {
                    currentState = 'E';
                } else if(input == 'b') {
                    currentState = 'B';
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