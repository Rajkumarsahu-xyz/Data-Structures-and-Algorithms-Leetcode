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
    ListNode* partition(ListNode* head, int x) 
    {
        if(!head)
            return head;
        
        ListNode* p = head;
        ListNode* k = NULL;
        while(p)
        {
            if(p->val == x)
            {
                k = p;
                break;
            }
            p = p->next;
        }
        
        p = head;
        ListNode* h1 = NULL;
        ListNode* h2 = NULL;
        ListNode* l = NULL;
        ListNode* r = NULL;
        int i=0, j=0;
        // cout << "raj3" << endl;
        while(p)
        {
            if(p->val < x)
            {
                // cout << "raj4" << endl;
                if(i==0)
                {
                    h1 = p;
                    l = p;
                    i = 1;
                }
                else
                {
                    l->next = p;
                    l = l->next;
                }
            }
            
            else
            {
                // cout << "raj5" << endl;
                if(j==0)
                {
                    h2 = p;
                    r = p;
                    j = 1;
                }
                else
                {
                    r->next = p;
                    r = r->next;
                }
            }
            
            p = p->next;
        }
        
        if(r != NULL)
            r->next = NULL;
        
        if(l != NULL)
            l->next = h2;
        
        if(h1)
            return h1;
        else
            return h2;
    }
};