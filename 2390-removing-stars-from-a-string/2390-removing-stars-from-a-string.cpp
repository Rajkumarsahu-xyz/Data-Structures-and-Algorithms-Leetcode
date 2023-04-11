class Solution {
public:
    string removeStars(string s) 
    {
        stack<char> stk;
        
        stk.push(s[0]);
        for(int i=1; i<s.length(); i++)
        {
            if(s[i] == '*'  &&  stk.top() != '*')
            {
                stk.pop();
            }
            
            else
            {
                stk.push(s[i]);
            }
        }
        
        string p = "";
        while(!stk.empty())
        {
            p += stk.top();
            stk.pop();
        }
        
        reverse(p.begin(), p.end());
        return p;
    }
};