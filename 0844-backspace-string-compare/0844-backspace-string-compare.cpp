class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        stack<char> stk;
        
        // stk.push(s[0]);
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '#')
            {
                if(stk.empty())
                    continue;
                else
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
        // cout << p << endl;
        
        
        stack<char> stk2;
        for(int i=0; i<t.length(); i++)
        {
            if(t[i] == '#')
            {
                if(stk2.empty())
                    continue;
                else
                    stk2.pop();
            }
            
            else
            {
                stk2.push(t[i]);
            }
        }
        
        string p1 = "";
        while(!stk2.empty())
        {
            p1 += stk2.top();
            stk2.pop();
        }
        
        reverse(p1.begin(), p1.end());
        // cout << p1 << endl;
        
        if(p1 == p)
            return true;
        else
            return false;
    }
};