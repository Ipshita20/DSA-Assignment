#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insertAtBeginning(int val) {
    Node* newNode=new Node;
    newNode->data=val;
    newNode->next=head;
    head=newNode;
}

void insertAtEnd(int val) {
    Node* newNode=new Node;
    newNode->data=val;
    newNode->next=NULL;
    if (head==NULL) {
        head=newNode;
        return;
    }
    Node* temp=head;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
}

void insertBefore(int key, int val) {
    if (head==NULL) {
        cout<<"List is empty.\n";
        return;
    }
    if (head->data==key) { 
        insertAtBeginning(val);
        return;
    }
    Node* temp=head;
    while (temp->next!=NULL && temp->next->data!=key) {
        temp=temp->next;
    }
    if (temp->next==NULL) {
        cout<<"Node "<<key<<" not found.\n";
        return;
    }
    Node* newNode=new Node;
    newNode->data=val;
    newNode->next=temp->next;
    temp->next=newNode;
}
void insertAfter(int key, int val) {
    Node* temp=head;
    while (temp!=NULL && temp->data!=key) {
        temp=temp->next;
    }
    if (temp==NULL) {
        cout<<"Node "<<key<<" not found.\n";
        return;
    }
    Node* newNode=new Node;
    newNode->data=val;
    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteFromBeginning() {
    if (head==NULL) {
        cout<<"List is empty.\n";
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
}

void deleteFromEnd() {
    if (head==NULL) {
        cout<<"List is empty.\n";
        return;
    }
    if (head->next==NULL) { 
        delete head;
        head=NULL;
        return;
    }
    Node* temp=head;
    while (temp->next->next!=NULL) {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}

void deleteNode(int key) {
    if (head==NULL) {
        cout<<"List is empty.\n";
        return;
    }
    if (head->data==key) {
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
    Node* temp=head;
    while (temp->next!=NULL && temp->next->data!=key) {
        temp=temp->next;
    }
    if (temp->next==NULL) {
        cout<<"Node "<<key<<" not found.\n";
        return;
    }
    Node* toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
}

void searchNode(int key) {
    Node* temp=head;
    int pos=1;
    while (temp!=NULL) {
        if (temp->data==key) {
            cout<<"Node "<<key<<" found at position "<<pos<<endl;
            return;
        }
        temp=temp->next;
        pos++;
    }
    cout<<"Node "<<key<<" not found.\n";
}

void display() {
    if (head==NULL) {
        cout<<"List is empty.\n";
        return;
    }
    Node* temp=head;
    while (temp!=NULL) {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
int main() {
    int choice, val, key;
    while (true) {
        cout<<"\n--- Singly Linked List Menu ---\n";
        cout<<"1. Insert at Beginning\n";
        cout<<"2. Insert at End\n";
        cout<<"3. Insert Before a Node\n";
        cout<<"4. Insert After a Node\n";
        cout<<"5. Delete from Beginning\n";
        cout<<"6. Delete from End\n";
        cout<<"7. Delete Specific Node\n";
        cout<<"8. Search Node\n";
        cout<<"9. Display List\n";
        cout<<"10. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice) {
            case 1:
                cout<<"Enter value: ";
                cin>>val;
                insertAtBeginning(val);
                break;
            case 2:
                cout<<"Enter value: ";
                cin>>val;
                insertAtEnd(val);
                break;
            case 3:
                cout<<"Insert value: ";
                cin>>val;
                cout<<"Before node value: ";
                cin>>key;
                insertBefore(key, val);
                break;
            case 4:
                cout<<"Insert value: ";
                cin>>val;
                cout<<"After node value: ";
                cin>>key;
                insertAfter(key, val);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                cout<<"Enter node value to delete: ";
                cin>>key;
                deleteNode(key);
                break;
            case 8:
                cout<<"Enter value to search: ";
                cin>>key;
                searchNode(key);
                break;
            case 9:
                display();
                break;
            case 10:
                cout<<"Exiting...\n";
                return 0;
            default:
                cout<<"Invalid choice!\n";
        }
    }
}
