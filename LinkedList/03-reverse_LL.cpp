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

// Recursive soln - 3rd method
// this function will return head of the reversed list
Node* reverse1(Node* &head) {
    // base case
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* chotaHead = reverse1(head->next);

    head->next->next = head;
    head->next = NULL;

    return chotaHead;
}

Node* reverseLL(Node* head) {
    return reverse1(head);
}

// TC -> O(N)
// SC -> O(N)


// ##################################################################################

// Recursive Soln - 2nd method
// basically tried to convert the 1st method(iterative soln) to recursive way
// void reverse(Node* &head, Node* curr, Node* prev) {
//     // reaches the end of LL
//     if(curr == NULL) {
//         // prev becomes the last node and head for the reversed LL
//         head = prev;
//         return;
//     }

//     Node* forward = curr->next;
//     reverse(head, forward, curr);
//     crurr->next = prev;
// }

// Node* reverseLL(Node* head) {
//     Node* curr = head;
//     Node* prev = NULL;
//     reverse(head, curr, prev);
//     return head;
// }



// ##################################################################################

// Iterative Two-pointer approach
// 1st method
Node* reverseLL(Node* head) {
    if(head == NULL || head->next == NULL) {
        // empty list case or single node in list case
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
