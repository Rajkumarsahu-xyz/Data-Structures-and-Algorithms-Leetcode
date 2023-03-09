/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *fast = head, *slow = head;
        ListNode* ans = NULL;
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
            {
                ans = fast;
                break;
            }
        }
        
        if(ans)
        {
            if(slow != head)
            {
                slow = head;
                while(fast != slow)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                ans = fast;
            }
        }
        
        return ans;
    }
};