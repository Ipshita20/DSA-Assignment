#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node*right;
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
Node*insertBST(Node*root,int key){
    if(root==NULL)
        return new Node(key);
    if(key<root->data)
        root->left=insertBST(root->left,key);
    else if(key>root->data)
        root->right=insertBST(root->right,key);
    return root;
}
Node*minNode(Node*root){
    if(root==NULL)
        return NULL;
    Node*cur=root;
    while(cur->left!=NULL)
        cur=cur->left;
    return cur;
}
Node*deleteBST(Node*root,int key){
    if(root==NULL)
        return NULL;
    if(key<root->data)
        root->left=deleteBST(root->left,key);
    else if(key>root->data)
        root->right=deleteBST(root->right,key);
    else{
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }else if(root->left==NULL){
            Node*tmp=root->right;
            delete root;
            return tmp;
        }else if(root->right==NULL){
            Node*tmp=root->left;
            delete root;
            return tmp;
        }else{
            Node*succ=minNode(root->right);
            root->data=succ->data;
            root->right=deleteBST(root->right,succ->data);
        }
    }
    return root;
}
int maxDepth(Node*root){
    if(root==NULL)
        return 0;
    int l=maxDepth(root->left);
    int r=maxDepth(root->right);
    return (l>r?l:r)+1;
}
int minDepth(Node*root){
    if(root==NULL)
        return 0;
    if(root->left==NULL&&root->right==NULL)
        return 1;
    if(root->left==NULL)
        return 1+minDepth(root->right);
    if(root->right==NULL)
        return 1+minDepth(root->left);
    int l=minDepth(root->left);
    int r=minDepth(root->right);
    return (l<r?l:r)+1;
}
void inorder(Node*root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node*root=NULL;
    int arr[]={20,10,30,5,15,25,35,3,7,13,17};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        root=insertBST(root,arr[i]);
    cout<<"Inorder:";
    inorder(root);
    cout<<endl;
    root=insertBST(root,20);
    root=deleteBST(root,10);
    cout<<"AfterDelete(10):";
    inorder(root);
    cout<<endl;
    cout<<"MaxDepth:"<<maxDepth(root)<<endl;
    cout<<"MinDepth:"<<minDepth(root)<<endl;
    return 0;
}
