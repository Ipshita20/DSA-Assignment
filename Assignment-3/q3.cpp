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
            top = top + 1;    
            arr[top] = c;      
        }
    }
    char pop() {
        if (top == -1) {
            return '\0';  
        } else {
            char temp = arr[top];
            top = top - 1;
            return temp;
        }
    }
    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }
    int isEmpty() {
        if (top == -1) return 1;  
        else return 0;            
    }
};
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}
int isBalanced(string expr) {
    Stack s;
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty() == 1) return 0;  
            char topChar = s.pop();
            if (isMatchingPair(topChar, ch) == 0) return 0;
        }
    }
    if (s.isEmpty() == 1) 
    return 1;   
    else 
    return 0;                    
}
int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;
    if (isBalanced(expr) == 1)
        cout << "Balanced Expression" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}
