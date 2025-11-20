#include<iostream>
using namespace std;

int main(){
    int n,a[100];
    cout<<"Enter size: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    int left=0,right=n-1;
    while(left<right){
        int min=left,max=left;
        for(int i=left;i<=right;i++){
            if(a[i]<a[min])
            min=i;
            if(a[i]>a[max])
            max=i;
        }
        int t=a[left];
        a[left]=a[min];
        a[min]=t;
        if(max==left)
        max=min;
        t=a[right];
        a[right]=a[max];
        a[max]=t;
        left++;
        right--;
    }
    cout<<"Improved Selection Sorted: ";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
