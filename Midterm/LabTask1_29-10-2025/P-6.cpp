#include "lab2.h"

void findMaxMin() {
    int n;
    cout << "Enter Array Length: ";
    cin >> n;
    int arr[n];
    cout << "Enter Array Values:" << endl;
    for(int i=0; i<n; i++) {
        cout << "Value " << i+1 << ": ";
        cin >> arr[i];
    }
    
    int max = arr[0];
    int min = arr[0];
    
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    
    cout << "Maximum value: " << max << endl;
    cout << "Minimum value: " << min << endl;
}