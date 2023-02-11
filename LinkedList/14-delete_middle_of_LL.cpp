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
    if(head == NULL || head->next == NULL) return head;
    if(head->next->next == NULL) return head->next;
    
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;
}

Node* deleteMid(Node* head) {
    Node* mid = findMiddle(head);
    Node* temp = head;
    while(temp -> next != mid) {
        temp = temp -> next;
    }
    temp -> next = mid -> next;
    delete(mid);
    return head;
}