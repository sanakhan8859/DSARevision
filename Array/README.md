1. Second Largest Element
Problem: Ek array mein second largest number find karo without sorting, single pass mein.

Logic:

Do variables rakho: largest aur second_largest, dono ko initially INT_MIN set karo.
Array traverse karo:
Agar current element largest se bada hai, toh second_largest = largest kar do, aur largest = current element.
Agar current element largest se chhota hai par second_largest se bada hai, toh second_largest = current element.
Edge case: Agar array mein do se kam elements hain ya sab same hain, toh second largest nahi milega.
Code:

cpp
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
Example: [10, 5, 8, 12, 3] → largest = 12, second_largest = 10.

Time Complexity: O(n), single pass.

Space Complexity: O(1).



2. Rotate Array by K Steps
Problem: Array ko right ya left mein k steps rotate karo. Jaise [1, 2, 3, 4, 5] ko k=2 se right rotate karo toh [4, 5, 1, 2, 3].

Logic:

Effective rotation: k = k % n (n = array size), kyunki k bada ho sakta hai.
Three-step reverse method:
Poora array reverse karo.
Pehle k elements reverse karo.
Baaki (n-k) elements reverse karo.
Edge case: Agar k=0 ya n=1, toh no rotation.
Code (Right Rotate):

cpp
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
Example: [1, 2, 3, 4, 5], k=2 → [4, 5, 1, 2, 3].

Time Complexity: O(n).

Space Complexity: O(1).



3. Merge Two Sorted Arrays
Problem: Do sorted arrays merge karo into ek bada sorted array, bina extra space ke agar possible ho. Jaise [1, 3, 5] aur [2, 4, 6] → [1, 2, 3, 4, 5, 6].

Logic:

Backward merge (gap method se bhi kar sakte hain, par simple approach):
Ek naye array mein dono arrays ke elements compare karo aur chhota wala daal do.
Agar ek array khatam ho jaye, toh doosre ke baaki elements copy kar do.
Edge case: Agar koi array empty hai, toh doosra array hi answer hai.
Code:

cpp
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
Example: arr1 = [1, 3, 5], arr2 = [2, 4, 6] → result = [1, 2, 3, 4, 5, 6].

Time Complexity: O(n1 + n2).

Space Complexity: O(n1 + n2) for result array.


4. Approach: Two-pointer technique use karenge.

Ek pointer (nonZeroPos) rakho jo next non-zero element ke liye position track karega.

Array traverse karo, aur har non-zero element ko nonZeroPos pe daal do, aur nonZeroPos ko aage badhao.

Jab saare non-zero elements apni jagah pe aa jayein, baaki positions (nonZeroPos se end tak) zeros se fill kar do.

Steps:

nonZeroPos = 0 set karo.

Array traverse karo, agar arr[i] != 0 hai, toh arr[nonZeroPos] = arr[i] karo aur nonZeroPos++ karo.

Loop khatam hone ke baad, nonZeroPos se array ke end tak zeros daal do.

Edge Cases:

Agar array empty hai ya single element hai, toh kuch karne ki zarurat nahi.

Agar saare elements zero hain, toh array same rahega.

Agar koi zero nahi hai, toh array same rahega.

Time Complexity: O(n), kyunki ek pass mein non-zero elements move karte hain aur ek pass mein zeros fill karte hain.

Space Complexity: O(1), kyunki in-place kar rahe hain.

