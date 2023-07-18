// Approach:
// To solve this problem, you can use a min-heap or priority queue data structure. Here's a step-by-step approach:

// Create a min-heap or priority queue and initialize it with the first element from each linked list. The heap should be ordered based on the node values.
// Initialize a new linked list and a pointer to the head of the merged list.
// While the min-heap is not empty:
// Extract the minimum element from the min-heap. This will be the smallest value among the current heads of all linked lists.
// Append this minimum element to the merged list.
// Move the pointer of the merged list to the newly added node.
// If there is a next node in the linked list from which the minimum element was extracted, add it to the min-heap.
// Return the head of the merged list.
// This approach ensures that we always extract the smallest element from the heap and maintain the sorted order while merging the linked lists.

// lists vector consists of heads of all linkedlists

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        int k = lists.size();
        ListNode* head = NULL;
        ListNode* tail = NULL;

        for(int i=0; i<k; i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        } 

        while(!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            // merging part
            if(head == NULL) {
                head = node;
                tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }

            // pushing the next linkedlist node into the pq
            if(node->next != NULL) {
                pq.push(node->next);
            }
        }
        return head;
    }
};