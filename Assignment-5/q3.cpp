#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class LinkedList{
public:
    Node* head;
    LinkedList(){
        head=NULL;
    }
    void insert(int val){
        Node* newNode=new Node(val);
        if(head==NULL)
            head=newNode;
        else{
            Node* temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newNode;
        }
    }
    void findMiddle(){
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<"Middle element is "<<slow->data<<endl;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    cout<<"Linked List: ";
    list.display();
    list.findMiddle();
    return 0;
}

