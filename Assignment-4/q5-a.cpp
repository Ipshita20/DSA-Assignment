#include<iostream>
using namespace std;
#define SIZE 100
class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue()
     { 
        front=-1;
         rear=-1;
     }
    bool isEmpty() 
    { 
        return (front==-1); 
    }
    void enqueue(int x) {
        if (rear==SIZE-1) {
            cout<<"Queue Overflow\n";
            return;
        }
        if (front==-1) 
        front=0;
        arr[++rear]=x;
    }
    int dequeue() {
        if (isEmpty()) {
            cout<<"Queue Underflow\n";
            return -1;
        }
        int val=arr[front++];
        if (front>rear) 
        front=rear=-1; 
        return val;
    }
    int peek() {
        if (!isEmpty()) 
        return arr[front];
        return -1;
    }
};
class Stack {
    Queue q1, q2;
public:
    void push(int x) {
        if (q1.isEmpty()) {
            q1.enqueue(x);
            while (!q2.isEmpty())
                q1.enqueue(q2.dequeue());
        }
        else {
            q2.enqueue(x);
            while (!q1.isEmpty())
                q2.enqueue(q1.dequeue());
        }
    }
    int pop() {
        if (q1.isEmpty() && q2.isEmpty()) {
            cout<<"Stack Underflow\n";
            return -1;
        }
        if (!q1.isEmpty()) 
        return q1.dequeue();
        else 
        return q2.dequeue();
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<endl; 
    cout<<s.pop()<<endl; 
    cout<<s.pop()<<endl;
}
