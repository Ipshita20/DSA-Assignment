#include<iostream>
using namespace std;

class Circular{
public:
    int data;
    Circular*next;
    Circular(int val){
        data=val;
        next=NULL;
    }
};
class CircularLinkedList{
public:
    Circular*head;
    CircularLinkedList(){
        head=NULL;
    }
    void insertEnd(int val){
        Circular*node=new Circular(val);
        if(head==NULL){
            head=node;
            node->next=head;
            return;
        }
        Circular*temp=head;
        while(temp->next!=head)
        temp=temp->next;
        temp->next=node;
        node->next=head;
    }
    void displayWithHeadRepeat(){
        if(head==NULL){cout<<endl;return;}
        Circular*temp=head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<head->data<<endl;
    }
};
int main(){
    CircularLinkedList cll;
    cll.insertEnd(20);
    cll.insertEnd(100);
    cll.insertEnd(40);
    cll.insertEnd(80);
    cll.insertEnd(60);
    cll.displayWithHeadRepeat(); 
    return 0;
}
