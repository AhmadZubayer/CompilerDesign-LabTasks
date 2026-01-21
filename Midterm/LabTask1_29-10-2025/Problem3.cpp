#include<iostream>
using namespace std;

bool isComment(string s) {
    if((int)s[0] == 47 && (int)s[1] == 47){
        return true;
    } else if((int)s[0] == 47 && (int)s[1] == 42) {
        if ((int)s[s.length()-2] == 42 && (int)s[s.length()-1] == 47)  {
            return true;
        }
    } else {
        return false;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if (isComment(s)) {
        cout << "Comment" << endl;
    }
    else {
        cout << "Not Comment" << endl;
    }   
    return 0;
}