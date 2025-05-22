#include <iostream>
using namespace std;

void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateArray(int arr[], int n, int k) {
    k = k % n; // Effective rotation
    if (k == 0) return;
    reverse(arr, 0, n-1); // Reverse full array
    reverse(arr, 0, k-1); // Reverse first k elements
    reverse(arr, k, n-1); // Reverse remaining elements
}

int main() {
    int n, k;
    
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
   // cout << "Kitne steps rotate karna hai: ";
    cin >> k;
    rotateArray(arr, n, k);
    cout << "Rotated array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}