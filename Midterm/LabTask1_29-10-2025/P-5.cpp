#include "lab2.h"

void findAverage() {
    int n;
    cout << "Enter Array Length: ";
    cin >> n;
    int arr[n];
    cout << "Enter Array Values:" << endl;
    for(int i=0; i<n; i++) {
        cout << "Value " << i+1 << ": ";
        cin >> arr[i];
    }
    
    int arrSum = 0;
    for(int i=0; i<n; i++) {
        arrSum += arr[i];
    }
    
    double avgVal = (double)arrSum / n;
    cout << "AVERAGE VALUE: " << avgVal << endl;
}