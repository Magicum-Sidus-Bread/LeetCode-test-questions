//
// Created by Susancutie on 2022/8/28.
//


class Solution {
public:
    int getlength(ListNode* head){
        int length = 0;
        while (head) {
            ++length;
            head = head->next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        int length = getlength(head);
        ListNode* cur = dummy;
        for(int i = 1;i < length - n + 1;++i){
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return dummy->next;
    }
};
