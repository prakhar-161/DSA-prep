// GFG - medium
// Leetcode - Hard
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


Node* kReverse(Node *head, int k) {
    // for the case if there is a group at last with size < k
    int size = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp -> next;
        size++;
    }
    if(size < k) return head;
    
    // base case
    if(head == NULL) return NULL;

    // step-1 : reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int count = 0;

    while(curr != NULL && count < k) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // step-2 : recursion handles other cases
    // recursion starts from forward variable 
    if(forward != NULL) {
        head -> next = kReverse(forward, k);
    }

    // step-3 : return head of reverse list
    return prev;
}