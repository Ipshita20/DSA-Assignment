#include <iostream>
#include <string>
using namespace std;
#define MAX 100   
class Stack {
    char arr[MAX];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(char c) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = c;
        }
    }
    char pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return '\0';   
        } else {
            return arr[top--];
        }
    }
    int isEmpty() {   // return int instead of bool
        if (top == -1)
            return 1;
        else
            return 0; 
    }
};
int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;   
    Stack s;
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }
    string rev = "";
    while (s.isEmpty() == 0) {  
        rev += s.pop();
    }
    cout << "Reversed string: " << rev << endl;
    return 0;
}
