#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* newNode(int data){
    Node* temp=new Node();
    temp->data=data;
    temp->next=NULL;
    return temp;
}
Node* reverseList(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void printList(Node* head){
    while(head!=NULL){
        cout<<head->data;
        if(head->next!=NULL)
            cout<<"->";
        head=head->next;
    }
    cout<<"->NULL"<<endl;
}
int main(){
    Node* head=newNode(1);
    head->next=newNode(2);
    head->next->next=newNode(3);
    head->next->next->next=newNode(4);
    cout<<"Original List: ";
    printList(head);
    head=reverseList(head);
    cout<<"Reversed List: ";
    printList(head);
    return 0;
}
