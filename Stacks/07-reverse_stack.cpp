#include<bits/stdc++.h>
using namespace std;

// uses logic of inserting element at the bottom of the stack
class Solution {
    public:
    void reverseStack(stack<int> &stack) {
        // base case
        if(stack.empty()) return;

        int num = stack.top();
        stack.pop();

        reverseStack(stack);

        insertAtBottom(num);
    }

    void insertAtBottom(stack<int> &stack, int x) {
        // base case
        if(stack.empty()) {
            stack.push(x);
            return;
        }

        int ele = stack.top();
        stack.pop();

        insertAtBottom(stack, x);

        stack.push(ele);
    }
};