#include<iostream>
using namespace std;
int findMissingBinary(int arr[], int n) {
    int left = 0, right = n - 1;
    int start = arr[0];  
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] != start + mid) {
            if (mid == 0 || arr[mid - 1] == start + mid - 1) 
                return start + mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1; 
}
int main() {
    int arr[] = {5, 6, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Missing number is " << findMissingBinary(arr, n);
    return 0;
}
