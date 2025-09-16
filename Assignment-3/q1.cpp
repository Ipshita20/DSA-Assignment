#include<iostream>
using namespace std;
#define MAX 5
class Stack{
    int arr[MAX],top;
public:
    Stack(){top=-1;}
    void push(int x){
        if(isFull()){
            cout<<"Stack Overflow! Cannot push "<<x<<endl;
        }
        else{
            top++;
            arr[top]=x;
            cout<<x<<" pushed into stack."<<endl;
        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow! Cannot pop."<<endl;
        }
        else{
            int val=arr[top];
            top--;
            cout<<val<<" popped from stack."<<endl;
        }
    }
    void peek(){
        if(isEmpty()){
            cout<<"Stack is empty. Nothing to peek."<<endl;
        }
        else{
            cout<<"Top element is: "<<arr[top]<<endl;
        }
    }
    int isEmpty()
    {
        return top==-1;
    }
    int isFull()
    {
        return top==MAX-1;
    }
    void display(){
        if(isEmpty()){
            cout<<"Stack is empty."<<endl;
        }
        else{
            cout<<"Stack elements are: ";
            for(int i=top;i>=0;i--)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Stack s;
    int choice,val;
    do{
        cout<<"\n---- Stack Menu ----\n";
        cout<<"1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to push: ";
                cin>>val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                if(s.isEmpty())
                {
                    cout<<"Stack is Empty."<<endl;
                }
                else
                {
                    cout<<"Stack is NOT Empty."<<endl;
                }
                break;
            case 5:
                if(s.isFull())
                {
                    cout<<"Stack is Full."<<endl;
                }
                else
                {
                    cout<<"Stack is NOT Full."<<endl;
                }
                break;
            case 6:
                s.display();
                break;
            case 7:
                cout<<"Exiting program."<<endl;
                break;
            default:
                cout<<"Invalid choice. Try again."<<endl;
        }
    }while(choice!=7);
    return 0;
}
