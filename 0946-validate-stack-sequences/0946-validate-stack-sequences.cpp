class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)    
    {
        stack<int> stk;
        int n = pushed.size();
        int i=0, j=0;
        while(true)
        {
            // stk.push(pushed[i]);
            if(!stk.empty() && stk.top() == popped[j])
            {
                stk.pop();
                j++;
            }
            
            else if(i == n && stk.top() != popped[j])
                return false;
            
            else
            {
                stk.push(pushed[i]);
                i++;
            }
            
            if(i==n && j==n)
                return true;
        }
        
        
    }
};