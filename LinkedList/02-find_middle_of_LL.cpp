// GFG
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

// EASY


// Approach - 1
int getLength(Node* head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

Node* findMiddle(Node* head) {
    int len = getLength(head);
    int ans = len/2;

    Node* temp = head;
    int cnt = 0;
    while(cnt < ans) {
        temp = temp -> next;
        cnt++;
    }
    return temp;
}

// TC -> O(N) + O(N/2) ~ O(N)
// SC -> O(1)

// We optimize this solution now

// Approach - 2
Node* findMiddle(Node* head) {
    // corner cases
    if(head == NULL || head->next == NULL) return head;
    if(head->next->next == NULL) return head->next;

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {  // specifically handled for even size case
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    // return slow->data;
    return slow;
}

// TC -> O(N/2)
// SC -> O(1)