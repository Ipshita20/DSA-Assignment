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
    int size() 
    {
         return (isEmpty()?0:rear-front+1); 
    }
    void enqueue(int x) {
        if (rear==SIZE-1) {
            cout<<"Queue Overflow\n";
            return;
        }
        if (front==-1) 
        front=0;
        arr[++rear] = x;
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
    Queue q;
public:
    void push(int x) {
        int sz=q.size();
        q.enqueue(x);
        for (int i=0; i<sz; i++) {
            q.enqueue(q.dequeue());
        }
    }
    int pop() {
        if (q.isEmpty()) {
            cout<<"Stack Underflow\n";
            return -1;
        }
        return q.dequeue();
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<endl; 
    cout<<
    s.pop()<<endl; 
    cout<<s.pop()<<endl; 
}
