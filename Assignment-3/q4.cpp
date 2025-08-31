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

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (ch == ' ') continue; 

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (s.isEmpty() == 0 && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); 
        }
        else { 
            while (s.isEmpty() == 0 && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }
    while (s.isEmpty() == 0) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an Infix Expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression = " << postfix << endl;

    return 0;
}
