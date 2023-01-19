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
    ListNode* reverseList(ListNode* head) 
    {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode *nxt = head->next, *curr = head, *prev = NULL;
        while(curr)
        {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(nxt)
                nxt = nxt->next;
        }
        
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        ListNode* k = reverseList(head);
        ListNode *p = k, *q = k->next;
        while(q)
        {
            if(q->val < p->val)
            {
                ListNode *t = q;
                p->next = q->next;
                q = q->next;
                delete t;
            }
            
            else
            {
                p = p->next;
                q = q->next;
            }
        }
        
        k = reverseList(k);
        return k;
    }
};