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

// APPROACH - 2 (Floyd Cycle Detection Algorithm) (Two-pointer approach)
bool detectLoop(Node* head) {
    // corner cases
    if(head == NULL) return false;
    if(head -> next == NULL) return false;

    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL) {
        slow = slow -> next;
        fast = fast -> next;
        while(fast != NULL) {
            fast = fast -> next;
        }
        
        if(slow == fast) {
            cout << "Cycle present at " << slow -> data << endl;
            return true;
        }
    }
    return false;
}

Node* startingNodeOfLoop(Node* head) {
    Node* slow = NULL;
    Node* fast = NULL;

    while(slow != NULL && fast != NULL) {
        slow = slow -> next;
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        if(slow == fast) {
            break;
        }
    }

    slow = head;
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}

void removeLoop(Node* head) {
    if(head == NULL) return;

    Node* startNodeOfLoop = startingNodeOfLoop(head);
    Node* temp = startNodeOfLoop;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = NULL;

}

// TC -> O(N)
// SC -> O(1)

// -------------------------------------------------------------------------------------------------


// APPROACH - 1 (Using Map)
// bool detectLoop(Node* head) {
//     if(head == NULL) return false;

//     map<Node*, bool> vis;
//     Node* temp = head;
//     while(temp != NULL) {
//         // if node is not visited in map or not found in map
//         // we insert into map if node not found in map
//         // if(vis.find(temp) == vis.end()) {
//         //     vis[temp] = true;
//         // }
//         // else return true;       // cycle present

//         if(vis[temp] = true) {
//             cout << "Cycle present on element " << temp -> data << endl;
//             return true;
//         }

//         vis[temp] = true;

//         temp = temp -> next;
//     }
//     return false;
// }

// TC -> O(N)
// SC -> O(N)