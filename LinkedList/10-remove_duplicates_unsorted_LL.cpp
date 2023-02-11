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

// Unsorted Linkedlist
Node *removeDuplicates(Node *head) {
    if(head == NULL) return head;

    map<Node*, bool> mp;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        if(mp.find(temp -> data) == mp.end()) {
            mp[temp -> data] = true;
            prev = temp;
        }
        else {
            prev -> next = temp -> next;
            delete(temp);
        }
        temp = temp -> next;
    }
    return head;
}

// TC -> O(N)
// SC -> O(N)