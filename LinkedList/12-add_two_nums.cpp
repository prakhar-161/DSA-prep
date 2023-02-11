// Given two numbers represented by two linked lists of Size Nand M. The task is to return a sum list.
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

void insertAtTail(Node* &head, Node* &tail, int val) {
    Node* temp = new Node(val);
    // empty list
    if(head == NULL) {
        head = temp;
        tail = temp;
    }
    else {      //not empty list
        tail -> next = temp;
        tail = temp;
    }
}

// Method - 1 (kind of untidy code)
// Node* addLL(Node* first, Node* second) {
//     int carry = 0;
//     Node* ansHead = NULL;
//     Node* ansTail = NULL;

//     // first handle loop till there are nodes running in both LL for same indexes
//     while(first != NULL && second != NULL) {
//         int sum = first -> data + second -> data + carry;
//         digit = sum % 10;

//         insertAtTail(ansHead, ansTail, digit);

//         carry = sum / 10;

//         first = first -> next;
//         second = second -> next;
//     }
    
//     while(first != NULL) {
//         int sum = first -> data + carry;
//         digit = sum % 10;
//         insertAtTail(ansHead, ansTail, digit);
//         carry = sum / 10;
//         first = first -> next;
//     }

//     while(second != NULL) {
//         int sum = second -> data + carry;
//         digit = sum % 10;
//         insertAtTail(ansHead, ansTail, digit);
//         carry = sum / 10;
//         second = second -> next;
//     }

//     // if carry is left atlast for eg- 900 + 230 = 1130 (here carry = 1) which needs to be handled
//     while(carry != 0) {
//         int sum = carry;
//         digit = sum % 10;
//         insertAtTail(ansHead, ansTail, digit);
//         carry = sum / 10;
//     }
    
//     return ansHead;
// }

// Method - 2 (tidy code)
// Better understand in first one....consider that for revising
Node* addLL(Node* first, Node* second) {
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(first != NULL || second != NULL || carry != 0) {
        int val1 = 0;
        if(first != NULL) val1 = first -> data;
        
        int val2 = 0;
        if(second != NULL) val2 = second -> data;

        int sum = val1 + val2 + carry;
        digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;

        if(first != NULL) {
            first = first -> next;
        }
        if(second != NULL) {
            second = second -> next;
        }
    }
    return ansHead;
}

Node* addTwoLists(Node* first, Node* second) {
    first = reverseLL(first);
    second = reverseLL(second);

    Node* ans = addLL(first, second);

    ans = reverseLL(ans);
    return ans;
}