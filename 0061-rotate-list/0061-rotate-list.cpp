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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == NULL)
            return head;
        
        int size = 1;
        ListNode* t = head;
        while(t->next != NULL)
        {
            size++;
            t=t->next;
        }
        
        k %= size;
        t->next = head;
        while(size-k > 0)
        {
            //cout << t->val << endl;
            t = t->next;
            k++;
        }
        
        head = t->next;
        t->next = NULL;
        return head;
    }
};