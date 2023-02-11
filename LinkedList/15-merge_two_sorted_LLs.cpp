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

Node* solve(Node* first, Node* second) {
    // first list is the list in which we insert nodes of list2 when they fit in at the indexes between the nodes of the first list

    // if only one node is present in first LL
    if(first -> next == NULL) {
        first -> next = second;
        return first;
    }

    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;

    while(next1 != NULL && curr2 != NULL) {
        if(curr2 -> data >= curr1 -> data && curr2 -> data <= next1 -> data) {
            // node addition
            curr1 -> next = curr2;
            next2 = curr2 -> next;          // so that the LL2 doesnot get lost
            curr2 -> next = next1;

            // updating pointers to move forward
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            // move curr1 and next1 forward
            // go 1 step in the first list
            curr1 = next1;
            next1 = next1 -> next;

            if(next1 == NULL) {
                curr1 -> next = curr2;
                return first;
            }
        }
    }
    return first; 
}

Node* sortedMerge(Node* head1, Node* head2) {  
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    if(head1 -> data <= head2 -> data) {
        solve(head1, head2);
    }
    else {
        solve(head2, head1);
    }
}  