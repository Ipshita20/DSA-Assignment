#include<iostream>
using namespace std;

class Doubly{
public:
    int data;
    Doubly*prev;
    Doubly*next;
    Doubly(int value){
        data=value;
        prev=NULL;
        next=NULL;
    }
};
class DoublyList{
public:
    Doubly*head;
    DoublyList(){
        head=NULL;
    }
    void insertAtBeg(int value){
        Doubly*node=new Doubly(value);
        node->next=head;
        if(head!=NULL)
            head->prev=node;
        head=node;
    }
    void insertAtEnd(int value){
        Doubly*node=new Doubly(value);
        if(head==NULL){
            head=node;
            return;
        }
        Doubly*temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=node;
        node->prev=temp;
    }
    bool insertAfter(int key,int value){
        Doubly*temp=head;
        while(temp!=NULL&&temp->data!=key)
            temp=temp->next;
        if(temp==NULL)
            return false;
        Doubly*node=new Doubly(value);
        node->next=temp->next;
        node->prev=temp;
        if(temp->next!=NULL)
            temp->next->prev=node;
        temp->next=node;
        return true;
    }
    bool insertBefore(int key,int value){
        Doubly*temp=head;
        while(temp!=NULL&&temp->data!=key)
            temp=temp->next;
        if(temp==NULL)
            return false;
        if(temp==head){
            insertAtBeg(value);
            return true;
        }
        Doubly*node=new Doubly(value);
        node->next=temp;
        node->prev=temp->prev;
        temp->prev->next=node;
        temp->prev=node;
        return true;
    }
    bool deleteNode(int key){
        Doubly*temp=head;
        while(temp!=NULL&&temp->data!=key)
            temp=temp->next;
        if(temp==NULL)
            return false;
        if(temp->prev!=NULL)
            temp->prev->next=temp->next;
        else
            head=temp->next;
        if(temp->next!=NULL)
            temp->next->prev=temp->prev;
        delete temp;
        return true;
    }
    bool searchNode(int key){
        Doubly*temp=head;
        while(temp!=NULL){
            if(temp->data==key)
                return true;
            temp=temp->next;
        }
        return false;
    }
    void display(){
        Doubly*temp=head;
        cout<<"Doubly Linked List: ";
        while(temp!=NULL){
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
    Circular(int value){
        data=value;
        next=NULL;
    }
};
class CircularList{
public:
    Circular*head;
    CircularList(){
        head=NULL;
    }
    void insertAtBeg(int value){
        Circular*node=new Circular(value);
        if(head==NULL){
            head=node;
            node->next=head;
            return;
        }
        Circular*last=head;
        while(last->next!=head)
            last=last->next;
        node->next=head;
        last->next=node;
        head=node;
    }
    void insertAtEnd(int value){
        Circular*node=new Circular(value);
        if(head==NULL){
            head=node;
            node->next=head;
            return;
        }
        Circular*last=head;
        while(last->next!=head)
            last=last->next;
        last->next=node;
        node->next=head;
    }
    bool insertAfter(int key,int value){
        if(head==NULL)
            return false;
        Circular*temp=head;
        do{
            if(temp->data==key){
                Circular*node=new Circular(value);
                node->next=temp->next;
                temp->next=node;
                return true;
            }
            temp=temp->next;
        }while(temp!=head);
        return false;
    }
    bool insertBefore(int key,int value){
        if(head==NULL)
            return false;
        Circular*last=head;
        while(last->next!=head)
            last=last->next;
        Circular*prev=last;
        Circular*temp=head;
        do{
            if(temp->data==key){
                Circular*node=new Circular(value);
                node->next=temp;
                prev->next=node;
                if(temp==head)
                    head=node;
                return true;
            }
            prev=temp;
            temp=temp->next;
        }while(temp!=head);
        return false;
    }
    bool deleteNode(int key){
        if(head==NULL)
            return false;
        Circular*last=head;
        while(last->next!=head)
            last=last->next;
        Circular*prev=last;
        Circular*temp=head;
        do{
            if(temp->data==key){
                if(temp==head&&temp->next==head){
                    delete temp;
                    head=NULL;
                    return true;
                }
                prev->next=temp->next;
                if(temp==head)
                    head=temp->next;
                delete temp;
                return true;
            }
            prev=temp;
            temp=temp->next;
        }while(temp!=head);
        return false;
    }
    bool searchNode(int key){
        if(head==NULL)
            return false;
        Circular*temp=head;
        do{
            if(temp->data==key)
                return true;
            temp=temp->next;
        }while(temp!=head);
        return false;
    }
    void display(){
        if(head==NULL){
            cout<<"Circular Linked List is empty"<<endl;
            return;
        }
        Circular*temp=head;
        cout<<"Circular Linked List: ";
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }
};
int main(){
    DoublyList dll;
    CircularList cll;
    int choice,subChoice,value,key;
    while(true){
        cout<<"\n=== MAIN MENU ===\n";
        cout<<"1.Doubly Linked List\n";
        cout<<"2.Circular Linked List\n";
        cout<<"0.Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==0)
            break;
        switch(choice){
        case 1:
            while(true){
                cout<<"\n--- DOUBLY LINKED LIST ---\n";
                cout<<"1.Insert at Beginning\n";
                cout<<"2.Insert at End\n";
                cout<<"3.Insert After Node\n";
                cout<<"4.Insert Before Node\n";
                cout<<"5.Delete Node\n";
                cout<<"6.Search Node\n";
                cout<<"7.Display\n";
                cout<<"8.Back\n";
                cout<<"Enter choice: ";
                cin>>subChoice;
                if(subChoice==8)
                    break;
                switch(subChoice){
                case 1:
                    cout<<"Enter value: ";
                    cin>>value;
                    dll.insertAtBeg(value);
                    break;
                case 2:
                    cout<<"Enter value: ";
                    cin>>value;
                    dll.insertAtEnd(value);
                    break;
                case 3:
                    cout<<"Enter key: ";
                    cin>>key;
                    cout<<"Enter value: ";
                    cin>>value;
                    if(!dll.insertAfter(key,value))
                        cout<<"Key not found\n";
                    break;
                case 4:
                    cout<<"Enter key: ";
                    cin>>key;
                    cout<<"Enter value: ";
                    cin>>value;
                    if(!dll.insertBefore(key,value))
                        cout<<"Key not found\n";
                    break;
                case 5:
                    cout<<"Enter key to delete: ";
                    cin>>key;
                    if(!dll.deleteNode(key))
                        cout<<"Key not found\n";
                    break;
                case 6:
                    cout<<"Enter key to search: ";
                    cin>>key;
                    cout<<(dll.searchNode(key)?"Found\n":"Not found\n");
                    break;
                case 7:
                    dll.display();
                    break;
                default:
                    cout<<"Invalid choice\n";
                }
            }
            break;
        case 2:
            while(true){
                cout<<"\n--- CIRCULAR LINKED LIST ---\n";
                cout<<"1.Insert at Beginning\n";
                cout<<"2.Insert at End\n";
                cout<<"3.Insert After Node\n";
                cout<<"4.Insert Before Node\n";
                cout<<"5.Delete Node\n";
                cout<<"6.Search Node\n";
                cout<<"7.Display\n";
                cout<<"8.Back\n";
                cout<<"Enter choice: ";
                cin>>subChoice;
                if(subChoice==8)
                    break;
                switch(subChoice){
                case 1:
                    cout<<"Enter value: ";
                    cin>>value;
                    cll.insertAtBeg(value);
                    break;
                case 2:
                    cout<<"Enter value: ";
                    cin>>value;
                    cll.insertAtEnd(value);
                    break;
                case 3:
                    cout<<"Enter key: ";
                    cin>>key;
                    cout<<"Enter value: ";
                    cin>>value;
                    if(!cll.insertAfter(key,value))
                        cout<<"Key not found\n";
                    break;
                case 4:
                    cout<<"Enter key: ";
                    cin>>key;
                    cout<<"Enter value: ";
                    cin>>value;
                    if(!cll.insertBefore(key,value))
                        cout<<"Key not found\n";
                    break;
                case 5:
                    cout<<"Enter key to delete: ";
                    cin>>key;
                    if(!cll.deleteNode(key))
                        cout<<"Key not found\n";
                    break;
                case 6:
                    cout<<"Enter key to search: ";
                    cin>>key;
                    cout<<(cll.searchNode(key)?"Found\n":"Not found\n");
                    break;
                case 7:
                    cll.display();
                    break;
                default:
                    cout<<"Invalid choice\n";
                }
            }
            break;
        default:
            cout<<"Invalid choice\n";
        }
    }
    return 0;
}