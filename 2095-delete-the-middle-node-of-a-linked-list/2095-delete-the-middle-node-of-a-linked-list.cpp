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
    ListNode* deleteMiddle(ListNode* head) 
    {
        ListNode *t = head;
        ListNode *p = head;
        
        if(head->next == NULL)
            return NULL;
        if(head->next->next==NULL)
        {
            head->next=NULL;
            return head;
        }
        
        while(t->next != NULL)
        {
            t = t->next;
            p = p->next;
            if(t->next != NULL)
            {
                t = t->next;
            }
        }
        
        ListNode *temp = p->next;
        if(temp) 
        {
            p->val = temp->val;
            p->next = temp->next;
            temp->next = NULL;
        }   
        delete(temp);
        
        return head;
        
    }
};