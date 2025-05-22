#include <bits/stdc++.h>
using namespace std;

void moveZerosToEnd(int arr[], int n) {
    int nonZeroPos = 0; // Next position for non-zero element
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[nonZeroPos] = arr[i];
            nonZeroPos++;
        }
    }
    while (nonZeroPos < n) {
        arr[nonZeroPos] = 0;
        nonZeroPos++;
    }
}

int main() {
    int n;
    cin >> n; // Size input 
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Elements input 
    }
    
    moveZerosToEnd(arr, n);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}