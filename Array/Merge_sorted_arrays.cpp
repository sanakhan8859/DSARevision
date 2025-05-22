#include <iostream>
using namespace std;

void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    while (i < n1) result[k++] = arr1[i++]; // Copy remaining from arr1
    while (j < n2) result[k++] = arr2[j++]; // Copy remaining from arr2
}

int main() {
    int n1, n2;

    cin >> n1;
    int arr1[n1];

    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    
    cin >> n2;
    int arr2[n2];
    
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }
    int result[n1 + n2];
    mergeSortedArrays(arr1, n1, arr2, n2, result);
    cout << "Merged sorted array: ";
    for (int i = 0; i < n1 + n2; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}