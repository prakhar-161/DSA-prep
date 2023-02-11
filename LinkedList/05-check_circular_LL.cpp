#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

// input
// 1 2 3 4 1 - true
// 1 2 3 4 5 6 7 - false

// Approach - 1
bool isCircularList(Node* head) {
    if(head == NULL) return true;
    
    Node* temp = head -> next;
    // traverse for non-circular and circular list
    while(temp != NULL && temp != head) {
        temp = temp -> next;
    }

    if(temp == NULL) return false;      // non-circular
    if(temp == head) return true;       // circular
}

// TC -> O(N)
// SC -> O(1)