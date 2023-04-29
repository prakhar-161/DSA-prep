#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(stack<int> &myStack, int x) {
        // base case
        if(myStack.empty()) {
            myStack.push(x);
            return;
        }

        int num = myStack.top();
        myStack.pop();

        solve(myStack, x);

        myStack.push(num);
    }

    stack<int> pushAtBottom(stack<int>& myStack, int x) {
        solve(myStack, x);
        return myStack;
    }
}

// void solve(stack<int> &myStack, int count, int x, int size) {
//         // base case
//         if(count == size) {
//             myStack.push(x);
//             return;
//         }

//         int num = myStack.top();
//         myStack.pop();

//         solve(myStack, count+1, x, size);

//         myStack.push(num);
// }

// stack<int> pushAtBottom(stack<int>& myStack, int x) 
// {    
//     int count = 0;
//     int size = myStack.size();
//     solve(myStack, count, x, size);
//     return myStack;
// }