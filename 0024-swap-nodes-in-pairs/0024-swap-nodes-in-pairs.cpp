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
    ListNode* swapPairs(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        ListNode *p=head, *q=head->next;
        ListNode* k = head->next;
        while(q)
        {
            p->next = q->next;
            q->next = p;
            ListNode *t = p->next;
            if(t == NULL || t->next == NULL)
            {
                break;
            }
            q = t->next;
            p->next = q;
            p = t;
        }
        
        return k;
    }
};