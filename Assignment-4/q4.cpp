#include <iostream>
using namespace std;
class MyQueue {
    char arr[1000];
    int front,rear;
public:
    MyQueue() {
        front=0;
        rear=0;
    }
    void push(char c) {
        arr[rear++]=c;
    }
    void pop() {
        if (!empty()) 
        front++;
    }
    char peek() {
        return arr[front];
    }
    bool empty() {
        return front==rear;
    }
};
void firstNonRepeating(const string &str) {
    int freq[256]={0};  
    MyQueue q;
    for (int i=0; i<str.size(); i++) {
        char ch=str[i];
        freq[(unsigned char)ch]++;
        q.push(ch);
        while (!q.empty() && freq[(unsigned char)q.peek()] > 1) {
            q.pop();
        }
        if (q.empty())
            cout<<-1<<" ";
        else
            cout<<q.peek()<<" ";
    }
    cout<<endl;
}
int main() {
    string input="aabc";   
    firstNonRepeating(input);
    return 0;
}