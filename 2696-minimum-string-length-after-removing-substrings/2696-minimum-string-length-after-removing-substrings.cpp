class Solution {
public:
    int minLength(string s) 
    {
        stack<char> stk;
        int n = s.length();
        for(int i=n-1; i>=0; i--)
        {
            stk.push(s[i]);
        }
        
        stack<char> remainingChars;
        while(!stk.empty())
        {
            char c1 = stk.top();
            stk.pop();
            if(!stk.empty())
            {
                char c2 = stk.top();
                stk.pop();
                if((c1!='A' || c2!='B') && (c1!='C' || c2!='D'))
                {
                    remainingChars.push(c1);
                    stk.push(c2);
                    // remainingChars.push(c2);
                }
                
                else
                {
                    if(!remainingChars.empty())
                    {
                        stk.push(remainingChars.top());
                        remainingChars.pop();
                    }
                }
            }
            
            else 
            {
                remainingChars.push(c1);
            }
        }
        
        return remainingChars.size();
    }
};