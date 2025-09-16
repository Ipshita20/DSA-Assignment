#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data=val;
        next=NULL;
    }
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head=NULL;
    }
    void insert(int val) {
        Node* newNode=new Node(val);
        if (!head) {
            head=newNode;
            return;
        }
        Node* temp=head;
        while (temp->next) {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    int deleteOccurrences(int key) {
        Node* temp=head;
        Node* prev=NULL;
        int count=0;
        while (temp) {
            if (temp->data==key) {
                count++;
                Node* toDelete=temp;
                temp = temp->next;   
                if (prev == NULL) {  
                    head = temp;
                } else {
                    prev->next=temp;
                }
                delete toDelete;    
            } else {
                prev=temp;
                temp=temp->next;
            }
        }
        return count;
    }
    void printList() {
        Node* temp=head;
        while (temp) 
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(3);
    list.insert(1);
    cout<<"Original List: ";
    list.printList();
    int key=1;
    int count=list.deleteOccurrences(key);
    cout<<"Occurrences of "<<key<<" = "<<count<<endl;
    cout<<"Modified List: ";
    list.printList();
    return 0;
}

