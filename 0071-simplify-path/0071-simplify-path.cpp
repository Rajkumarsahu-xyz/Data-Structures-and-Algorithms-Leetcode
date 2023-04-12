#include <bits/stdc++.h>

class Solution {
public:
    string simplifyPath(string path) 
    {
        stack<string> stk;
        stringstream ss(path);
        string token;
        
        while(getline(ss, token, '/'))
        {
            if(token == "..")
            {
                if(!stk.empty())
                    stk.pop();
            }
            else if(token == "."  || token == "")
                continue;
            else
                stk.push(token);
        }
        
        string ans = "";
        stack<string> stk2;
        while(!stk.empty())
        {
            stk2.push(stk.top());
            stk.pop();
        }
        
        while(!stk2.empty())
        {
            // cout << stk2.top() << endl;
            ans += "/";
            ans += stk2.top();
            stk2.pop();
        }
        
        if(ans.length() == 0)
            ans += "/";
        return ans;
        
    }
};