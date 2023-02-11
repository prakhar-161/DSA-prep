// Sort 0s, 1s, 2s in Linkedlist
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

// APPROACH - 2
// Data replacement not allowed
// We can form 3 LL's for 0, 1 and 2
// finally merge them to get the desired output
Node* sortList(Node* head) {
    // creating dummy nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    // creating seperate lists for 0s, 1s and 2s
    while(curr != NULL) {
        int val = curr -> data;
        if(val== 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(val == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(val == 2) {
            insertAtTail(twoTail, curr);
        }
        curr = curr -> next;
    }

    // merging the 3 sublists
    // Making sure that 1s list is not empty
    // corner cases handle
    if(oneHead -> next != NULL) zeroTail -> next = oneHead -> next;
    else zeroTail -> next = twoHead -> next;

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    // updating head for final answer
    head = zeroHead -> next;

    // deleting dummy nodes
    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);
    
    return head;
}

void insertAtTail(Node* &tail, Node* curr) {  
    tail -> next = curr;
    tail = curr;
}


// --------------------------------------------------------------------------------------------------

// APPROACH - 1 
// here, there is data replacement taking place
Node* sortList(Node* head) {
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    // counting occurences of 0s, 1s and 2s and storing them in the above 3 variables
    while(temp != NULL) {
        if(temp -> data == 0) zeroCount++;
        else if(temp -> data == 1) oneCount++;
        else if(temp -> data == 2) twoCount++;

        temp = temp -> data;
    }

    temp = head;
    while(temp != NULL) {
        if(zeroCount != 0) {
            temp -> data = 0;
            zeroCount--;
        }
        else if(oneCount != 0) {
            temp -> data = 1;
            oneCount--;
        }
        else if(twoCount != 0) {
            temp -> data = 2;
            twoCount--;
        }
        temp = temp -> next;
    }

    return head;
}

// TC -> O(N)
// SC -> O(1)