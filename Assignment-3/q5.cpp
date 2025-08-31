#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!" << endl;
        } else {
            top = top + 1;
            arr[top] = x;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return -1;
        } else {
            int temp = arr[top];
            top = top - 1;
            return temp;
        }
    }

    int isEmpty() {
        if (top == -1) return 1;
        else return 0;
    }
};

int evaluatePostfix(string postfix) {
    Stack s;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (ch == ' ') continue; 

        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');  
        }
        else {
            int val2 = s.pop();
            int val1 = s.pop();
            int result = 0;

            if (ch == '+') result = val1 + val2;
            else if (ch == '-') result = val1 - val2;
            else if (ch == '*') result = val1 * val2;
            else if (ch == '/') result = val1 / val2;

            s.push(result);
        }
    }

    return s.pop(); 
}

int main() {
    string postfix;
    cout << "Enter a Postfix Expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
