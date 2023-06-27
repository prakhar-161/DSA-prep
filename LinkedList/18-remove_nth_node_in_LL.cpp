// Approach - 1
class Solution {
public:
    int getLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sizeLL = getLength(head);
        int index = sizeLL - n - 1;
       
        ListNode* curr = head;
        int cnt = 0;
        if(index == -1) {
            curr = curr->next;
            return curr;
        }
        else {
            while(cnt < index) {
                curr = curr->next;
                cnt++;
            }
        }
        curr->next = curr->next->next;

        return head;
    }
};
// TC -> O(2N)
// SC -> O(1)

// Approach - 2
