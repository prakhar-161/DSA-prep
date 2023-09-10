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

// Input
// head = [1,2,3,4,5,6,7], k = 2
// O/p : [6,7,1,2,3,4,5]

class Solution {
public:
    Node* rotateRight(Node* head, int k) {

        // firstly, reach the last element 
        // last element -> head
        // 7 -> 1
        if(head == NULL || k == 0) return head;
        
        Node* temp = head;
        int n = 0;
        while(temp -> next != NULL) {
            temp = temp -> next;
            n++;        // n = 6
        }
        temp -> next = head;            // connect last node to first node

        // n = 6
        k = k % (n+1);          // incase, given k is larger than n
        int jump = n-k;
        temp = head;
        while(jump) {
            temp = temp -> next;
            jump--;
        }
        // temp -> 5
        Node* returnHead = temp -> next;
        temp -> next = NULL;

        return returnHead;
    }
};