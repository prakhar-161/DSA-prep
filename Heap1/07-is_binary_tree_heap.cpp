#include<bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    private:
    bool isCBT(Node* tree) {

    }

    public: 
    bool isHeap(Node* tree) {
        if(isCBT(tree) && isMaxOrder(tree)) return true;
        else false;
    }
};

// 0-based indexing
// node = i 
// left = 2*i+1
// right = 2*i+2