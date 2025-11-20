#include<iostream>
using namespace std;

int main(){
    int A[]={1,2,3,4};
    int B[]={3,4,5,6};
    int n1=4,n2=4;
    cout<<"Common Elements: ";
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(A[i]==B[j])
            cout<<A[i]<<" ";
        }
    }
}
