#include<iostream>
using namespace std;

int main(){
    int n,a[100];
    cout<<"Enter size: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min])
            min=j;
        }
        int t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
    cout<<"Selection Sorted: ";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
