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

Node *removeDuplicates(Node *head) {
    if(head == NULL || head -> next == NULL) return head;

    Node* temp = head;
    Node* next_next;
    while(temp != NULL) {
        if(temp->next != NULL && temp -> data == temp -> next -> data) {
            next_next = temp -> next -> next;
            Node* nodeToDelete = temp -> next;
            free(nodeToDelete);
            temp -> next = next_next;
        }
        else {
            temp = temp -> next;
        }
    }
    return head;
}

// TC -> O(N)
// SC -> O(1)

// Approach - 2
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* curr = head;
        while(curr && curr->next) {
            if(curr->next->val == curr->val) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }
        return head;
    }
};

// Approach - 3
ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode* curr = head;
    while(curr) {
        while(curr->next && curr->next->val == curr->val) {
            curr->next = curr->next->next;
        }    
        curr = curr->next;
    }
    return head;
}