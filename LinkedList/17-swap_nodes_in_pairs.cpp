// APPROACH - 1
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            temp = temp -> next;
            size++;
        }
        if(size < 2) return head;

        if(head == NULL) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        int cnt = 0;
        while(curr != NULL && cnt < 2) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }

        if(forward != NULL) {
            head -> next = swapPairs(forward);
        }

        return prev;
    }
};

// APPROACH - 2
// slightly faster
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* curr = head;
        ListNode* forward = head->next;
        swap(curr->val, forward->val);
        while(curr->next->next != NULL && forward->next->next != NULL) {
            curr = curr->next->next;
            forward = forward->next->next;
            swap(curr->val, forward->val);
        }
        return head;
    }
}; 