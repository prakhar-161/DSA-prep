// stack ARR of size 'N+1', Task is to delete the middlemost element to make its size 'N'
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void solve(stack<int> &inputStack, int count, int size) {
        // base case
        if(count == size/2) {
            inputStack.pop();
            return;
        }

        int num = inputStack.top();
        inputStack.pop();

        // go to next call (recursion call)
        solve(inputStack, count+1, size);

        // coming back
        inputStack.push(num);
    }

    void deleteMiddle(stack<int> &inputStack, int N) {
        int count = 0;
        solve(inputStack, count, N);
    }
};