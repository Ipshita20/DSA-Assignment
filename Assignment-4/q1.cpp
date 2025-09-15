#include<iostream>
#define MAX 5  
using namespace std;
class Queue{
    int arr[MAX];
    int start, end;
public:
    Queue() {
        start=-1;
        end=-1;
    }
    bool isEmpty() {
        return (start==-1);
    }
    bool isFull() {
        return (end==MAX-1);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout<<"Queue Overflow! Cannot enqueue" << x << endl;
            return;
        }
        if (isEmpty()) {
            start=0;
        }
        arr[++end]=x;
        cout<<x<< " enqueued successfully." << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout<<"Queue Underflow! Cannot dequeue." << endl;
            return;
        }
        cout<<arr[start] << " dequeued successfully." << endl;
        if (start==end) {
            start=end=-1;
        } else {
            start++;
        }
    }
    void peek() {
        if (isEmpty()) {
            cout<<"Queue is empty." << endl;
        } else {
            cout<<"Start element is: " << arr[start] << endl;
        }
    }
    void display() {
        if (isEmpty()) {
            cout<<"Queue is empty." << endl;
            return;
        }
        cout<<"Queue elements: ";
        for (int i=start; i<=end; i++) {
            cout<<arr[i] << " ";
        }
        cout<<endl;
    }
};
int main() {
    Queue q;
    int choice, value;
    do {
        cout<<"\n--- Queue Menu ---\n";
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Peek\n";
        cout<<"4. Display\n";
        cout<<"5. Check if Empty\n";
        cout<<"6. Check if Full\n";
        cout<<"7. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                if (q.isEmpty())
                    cout<<"Queue is Empty." << endl;
                else
                    cout<<"Queue is not Empty." << endl;
                break;
            case 6:
                if (q.isFull())
                    cout<<"Queue is Full." << endl;
                else
                    cout<<"Queue is not Full." << endl;
                break;
            case 7:
                cout<<"Exiting program..." << endl;
                break;
            default:
                cout<<"Invalid choice! Try again." << endl;
        }
    } while(choice!=7);
    return 0;
}
