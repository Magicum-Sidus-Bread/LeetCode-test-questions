//
// Created by Susancutie on 2022/8/24.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p,*q,*tail,*head;
        head = new ListNode;
        tail = head;
        p = list1;
        q = list2;
        while(p != nullptr && q != nullptr){
            if(p->val <= q->val){
                tail->next = p;
                tail = p;
                p = p->next;
            }
            else {
                tail->next = q;
                tail = q;
                q = q->next;
            }
        }
        if(p == nullptr){
            tail->next = q;
        }
        if(q == nullptr){
            tail->next = p;
        }
        return head->next;
    }
};