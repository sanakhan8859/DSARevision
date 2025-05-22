#include <iostream>
#include <limits.h> // For INT_MIN
using namespace std;

int findSecondLargest(int arr[], int n) {
    if (n < 2) return -1; // Edge case
    int largest = INT_MIN, second_largest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] < largest) {
            second_largest = arr[i];
        }
    }
    return (second_largest == INT_MIN) ? -1 : second_largest;
}

int main() {
    int n;
    cout << "Array ka size daal: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = findSecondLargest(arr, n);
    if (result == -1) {
        cout << "Second largest nahi mila!" << endl;
    } else {
        cout << "Second largest element: " << result << endl;
    }
    return 0;
}