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
//(a)Search(Recursive)
Node*searchRec(Node*root,int key){
    if(root==NULL||root->data==key)
        return root;
    if(key<root->data)
        return searchRec(root->left,key);
    return searchRec(root->right,key);
}
//(a)Search(Non-Recursive / Iterative)
Node*searchIter(Node*root,int key){
    Node*cur=root;
    while(cur!=NULL){
        if(key==cur->data)
            return cur;
        else if(key<cur->data)
            cur=cur->left;
        else
            cur=cur->right;
    }
    return NULL;
}
//(b)Maximum element of the BST
Node*maxNode(Node*root){
    if(root==NULL)
        return NULL;
    Node*cur=root;
    while(cur->right!=NULL)
        cur=cur->right;
    return cur;
}
//(c)Minimum element of the BST
Node*minNode(Node*root){
    if(root==NULL)
        return NULL;
    Node*cur=root;
    while(cur->left!=NULL)
        cur=cur->left;
    return cur;
}
//(d)In-order successor of a given key
Node*inorderSuccessor(Node*root,int key){
    Node*target=searchIter(root,key);
    if(target==NULL)
        return NULL;
    if(target->right!=NULL)
        return minNode(target->right);
    Node*succ=NULL;
    Node*cur=root;
    while(cur!=NULL){
        if(key<cur->data){
            succ=cur;
            cur=cur->left;
        }else if(key>cur->data){
            cur=cur->right;
        }else
            break;
    }
    return succ;
}
//(e)In-order predecessor of a given key
Node*inorderPredecessor(Node*root,int key){
    Node*target=searchIter(root,key);
    if(target==NULL)
        return NULL;
    if(target->left!=NULL)
        return maxNode(target->left);
    Node*pred=NULL;
    Node*cur=root;
    while(cur!=NULL){
        if(key>cur->data){
            pred=cur;
            cur=cur->right;
        }else if(key<cur->data){
            cur=cur->left;
        }else
            break;
    }
    return pred;
}
int main(){
    Node*root=NULL;
    int arr[]={20,10,30,5,15,25,40,3,7,13,17,23,27,35,45};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        root=insertBST(root,arr[i]);
    int key=15;
    Node*r1=searchRec(root,key);
    cout<<"searchRec:"<<((r1!=NULL)?"Found":"NotFound")<<endl;
    Node*r2=searchIter(root,key);
    cout<<"searchIter:"<<((r2!=NULL)?"Found":"NotFound")<<endl;
    Node*mn=minNode(root);
    cout<<"Min:"<<(mn?mn->data:-1)<<endl;
    Node*mx=maxNode(root);
    cout<<"Max:"<<(mx?mx->data:-1)<<endl;
    Node*succ=inorderSuccessor(root,key);
    cout<<"SuccessorOf("<<key<<"):"<<(succ?succ->data:-1)<<endl;
    Node*pred=inorderPredecessor(root,key);
    cout<<"PredecessorOf("<<key<<"):"<<(pred?pred->data:-1)<<endl;
    return 0;
}
