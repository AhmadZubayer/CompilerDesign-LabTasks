#include <iostream>
using namespace std;

bool findOperator(string s)
{
    int arrOperators[6] = {37, 42, 43, 45, 47, 61};
    for (int i = 0; i < s.length(); i++){
        int a = (int)s[i];
        for (int j = 0; j < 6; j++){
            if (a == arrOperators[j]){
                cout << "operator: " << s[i] << endl;
                return true;
            } else {
                return false;
            }
        }
    }
}

int main()
{
    string s;
    cin >> s;
    if (!findOperator(s))
    {
        cout << "No operators found" << endl;
    }
    return 0;
}