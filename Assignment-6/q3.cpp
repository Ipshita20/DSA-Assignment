#include<iostream>
using namespace std;

class Doubly{
public:
    int data;
    Doubly*prev;
    Doubly*next;
    Doubly(int val)
    {
        data=val;
        prev=NULL;
        next=NULL;
    }
};
class DoublyLinkedList{
public:
    Doubly*head;
    DoublyLinkedList()
    {
        head=NULL;
    }
    void insertEnd(int val){
        Doubly* node=new Doubly(val);
        if(head==NULL)
        {
            head=node;
            return;
        }
        Doubly*temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=node;
        node->prev=temp;
    }
    int size(){
        int count=0;
        Doubly*temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    void display(){
        Doubly*temp=head;
        cout<<"Doubly Linked List: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
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
    int size(){
        if(head==NULL)
        return 0;
        int count=0;
        Circular*temp=head;
        do{
            count++;
            temp=temp->next;
        }while(temp!=head);
        return count;
    }
    void display(){
        if(head==NULL){
            cout<<"Circular Linked List is empty"<<endl;
            return;
        }
        cout<<"Circular Linked List: ";
        Circular*temp=head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }
};
int main(){
    DoublyLinkedList dll;
    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertEnd(30);
    dll.display();
    cout<<"Size of Doubly Linked List="<<dll.size()<<endl;
    CircularLinkedList cll;
    cll.insertEnd(1);
    cll.insertEnd(2);
    cll.insertEnd(3);
    cll.insertEnd(4);
    cll.display();
    cout<<"Size of Circular Linked List="<<cll.size()<<endl;
    return 0;
}
