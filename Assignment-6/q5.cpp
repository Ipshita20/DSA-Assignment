#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};
bool Circular(Node* head) {
    if (head==NULL)  
        return true;
    Node* temp=head->next;
    while(temp!=NULL && temp!=head) {
        temp=temp->next;
    }
    return (temp==head);
}
int main() {
    Node*head=new Node(2);
    head->next=new Node(4);
    head->next->next=new Node(6);
    head->next->next->next=new Node(7);
    head->next->next->next->next=new Node(5);
    cout<<"List 1 is "<<(Circular(head)?"Circular":"Not Circular")<<endl;
    head->next->next->next->next->next=head;
    cout<<"List 2 is "<<(Circular(head)?"Circular":"Not Circular")<<endl;
    return 0;
}
