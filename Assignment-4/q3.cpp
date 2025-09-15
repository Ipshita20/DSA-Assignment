#include <iostream>
using namespace std;
void interleave(int arr[], int n) {
    if (n%2!=0) {
        cout<<"Arrays element must be even!"<<endl;
        return;
    }
    int half=n/2;
    int firstHalf[half], secondHalf[half];
    for (int i=0; i<half; i++)
        firstHalf[i] = arr[i];
    for (int i=0; i<half; i++)
        secondHalf[i] = arr[i+half];
    int k=0;
    for (int i=0; i<half; i++) {
        arr[k++] = firstHalf[i];
        arr[k++] = secondHalf[i];
    }
}
int main() {
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    interleave(arr, n);
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;  
    return 0;
}