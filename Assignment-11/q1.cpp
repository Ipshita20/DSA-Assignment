#include<iostream>
using namespace std;

int main(){
    int nums[]={1,2,3,1};
    int n=4;
    bool dup=false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]==nums[j]){
                dup=true;
                break;
            }
        }
        if(dup)
        break;
    }
    cout<<(dup?"true":"false");
}
