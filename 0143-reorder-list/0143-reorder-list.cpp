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
    void reorderList(ListNode* head) 
    {
        stack<ListNode*> stk;
        ListNode *temp = head;
        
        int ctr = 1;
        
        while(temp->next) 
        {
            stk.push(temp->next);
            // cout << "a"<< endl;
            temp = temp->next;
            ctr++;
        }
        
        // cout << ctr << endl;
        
        temp = head;
        ctr--;
        while(temp->next && ctr>0)
        {
            ListNode* p = temp->next;
            temp->next = stk.top();
            stk.pop();
            temp = temp->next;
            ctr--;
            if(ctr > 0)
            {
                temp->next = p;
                temp = temp->next;
            }
            
            ctr--;
            // cout << ctr << endl;
        }
        // cout << "a" << endl;
        temp->next = NULL;
    }
};