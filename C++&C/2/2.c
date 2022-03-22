/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode  *head = NULL,*tail = NULL;
    int carry = 0;
    while(l1||l2){
        int n1 = l1 ? l1->val: 0;
        int n2 = l2 ? l2->val: 0;
        int sum = n1 + n2 + carry;
        //若未创建头结点，则创建头结点；若已创建头结点，则使用尾插法更新下一节点
        //创建头结点
        if(!head){
            head = tail = malloc(sizeof(struct ListNode));
            tail->val = sum % 10;
            tail->next = NULL;
        }
        //已经创建头结点，使用尾插法更新下一节点
        else{
            tail->next = malloc(sizeof(struct ListNode));
            tail = tail->next;
            tail->val = sum % 10;
            tail->next = NULL;
        }
        carry = sum / 10;
        if(l1){
            l1 = l1->next;
        }
        if(l2){
            l2 = l2->next;
        } 
    }
    //若遍历完所有的位，仍有进位，则链表需要额外创建一个节点，节点的值即为进位值
    if(carry > 0){
        tail->next = malloc(sizeof(struct ListNode));
        tail = tail->next;
        tail->val = carry;
        tail->next = NULL;
    }
    return head;
}