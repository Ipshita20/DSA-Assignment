#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};
int arr[100];
int idx=0;
bool found=false;
void collect(Node*root){
    if(root==NULL||found)
    return;
    for(int i=0;i<idx;i++){
        if(arr[i]==root->data){
            found=true;
            return;
        }
    }
    arr[idx++]=root->data;
    collect(root->left);
    collect(root->right);
}
int main(){
    Node*root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(3); 
    collect(root);
    cout<<(found?"Duplicates Found":"No Duplicates");
}
