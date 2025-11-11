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
bool BST(Node*root,Node*minNode=NULL,Node*maxNode=NULL){
    if(root==NULL)
        return true;
    if(minNode!=NULL&&root->data<=minNode->data)
        return false;
    if(maxNode!=NULL&&root->data>=maxNode->data)
        return false;
    return BST(root->left,minNode,root)&&BST(root->right,root,maxNode);
}
int main(){
    Node*root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(6);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    if(BST(root))
        cout<<"It is a BST"<<endl;
    else
        cout<<"It is not a BST"<<endl;
    root->right->left=new Node(5);
    root->right->right=new Node(2);
    if(BST(root))
        cout<<"It is a BST"<<endl;
    else
        cout<<"It is not a BST"<<endl;
    return 0;
}
