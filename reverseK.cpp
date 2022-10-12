class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for(int i = 0; i < k; i++){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
        }
        ListNode* cur = head, *prev = NULL, *ahead = NULL;
        for(int i = 0; i < k; i++){
            ahead = cur->next;
            cur->next = prev;
            prev = cur;
            cur = ahead;
        }
        head->next = reverseKGroup(cur, k);
        return prev;
        
    }
};
