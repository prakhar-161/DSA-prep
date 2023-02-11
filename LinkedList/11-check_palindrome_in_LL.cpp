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

Node* findMiddle(Node* head) {
    if(head == NULL || head -> next == NULL) return head;
    if(head -> next -> next == NULL) return head -> next;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {
        slow = slow -> next;
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        return slow;
    }
}

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if(head -> next == NULL) return true;

    // step-1
    Node* mid = findMiddle(head);

    // step-2
    // reverse LL after middle node
    Node* temp = mid -> next;
    mid -> next = reverse(temp);

    // step-3
    // compare both halves
    Node* head1 = head;
    Node* head2 = mid -> next;
    while(head2 != NULL) {
        if(head1 -> data != head2 -> data) {
            return false;
        }

        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    // step-4 - repeat step2
    temp = mid -> next;
    mid -> next = reverse(temp);

    return true;
}