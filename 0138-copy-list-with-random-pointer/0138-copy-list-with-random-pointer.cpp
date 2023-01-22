/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(!head) 
            return NULL;
        Node* copy = new Node(head->val);
        unordered_map<Node*, Node*>m;
        Node* start=copy, *header= head;
        
        while(header)
        {
            if(!header->next)
                start->next = NULL;
            else
                start->next = new Node(header->next->val);
            
            m[header] = start;
            header=header->next;
            start=start->next;
        }
        
        start = copy;
        while(head)
        {
            start->next = m[head->next];
            start->random = m[head->random];
            head = head->next;
            start = start->next;
        }
        
        return copy;
    }
};