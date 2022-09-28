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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *t = head, *p = head;
        while(n > 0)
        {
            t = t->next;
            n--;
        }
        
        while(t != NULL && t->next != NULL)
        {
            t = t->next;
            p = p->next;
        }
        
        if(t)
            p->next = p->next->next;
        else
            head = head->next;
        //delete t;
        
        return head;
    }
};