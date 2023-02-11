#include<bits/stdc++.h>
using namespace std;

class Stack {
    public:
    int top, size, *arr;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val) {
        if(size - top > 1) {
            top++;
            arr[top] = val;
        } 
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if(top>=0) {
            top--;
        }
        else {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek() {
        if(top>=0 && top<size) {
            return arr[top];
        }
        else {
            cout << "Stack is empty" << endl;
        }
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    Stack st(5);

    st.push(4);
    st.push(5);
    st.push(90);

    cout << st.peek() << endl;

    return 0;
}