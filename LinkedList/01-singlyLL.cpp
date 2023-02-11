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

    // destructor
    ~Node() {
        int value = this -> data;
        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "memory free for node with data" << value << endl;
    }
};

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void InsertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}   

void insertAtPosition(Node* &head, Node* &tail, int pos, int d) {
    Node* curr = head;
    if(pos == 1) {
        // insertAtHead(head, d);
        curr -> next = head;
        head = curr;
        return;
    }
    int cnt = 1;

    while(cnt < pos-1) {
        curr = curr -> next;
        cnt++;
    }

    // insert at last position
    if(curr -> next == NULL) {
        InsertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = curr -> next;
    curr -> next = nodeToInsert;
}

void deleteNode(int pos, Node* &head) {
    if(pos == 1) {
        Node* temp = head;
        head = head -> next;
        delete(temp);        
    }
    else {
        // deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        
        int cnt = 1;
        while(cnt <= pos) {
            
        }
    }
}