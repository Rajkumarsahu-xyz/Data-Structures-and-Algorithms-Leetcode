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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == NULL)
            return NULL;
        ListNode* odd = head;
        ListNode* even = head->next;
        
        ListNode* t = head->next;
        while(t != NULL && odd != NULL && odd->next != NULL && t->next != NULL)
        {
            odd->next = odd->next->next;
            t->next = t->next->next;
            odd = odd->next;
            t = t->next;
        }
        
        odd->next = even;
        return head;
    }
};