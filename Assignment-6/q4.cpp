#include<iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
    Node(char c) : data(c), prev(NULL), next(NULL) {}
};
void push(Node*& head, char c) {
    Node* node=new Node(c);
    if(!head) 
    { 
        head=node;
         return; 
        }
    Node* cur=head;
    while(cur->next) 
    cur=cur->next;
    cur->next=node;
    node->prev=cur;
}
bool Palindrome(Node* head) {
    if (!head||!head->next) 
    return true;  
    Node* left=head;
    Node* right=head;
    while(right->next) 
    right=right->next;
    while(left!=right && right->next!=left) {
        if(left->data!=right->data) 
        return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}
Node* String(const char* s) {
    Node* head=NULL;
    for (int i=0; s[i]!='\0'; ++i) 
    push(head, s[i]);
    return head;
}
int main() {
    Node* head1=String("LEVEL");   
    Node* head2=String("DSA");  
    cout<<(Palindrome(head1)?"YES":"NO")<< endl; 
    cout<<(Palindrome(head2)?"YES":"NO")<< endl; 
    return 0;
}
