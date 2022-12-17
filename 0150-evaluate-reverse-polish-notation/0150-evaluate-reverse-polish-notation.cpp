class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<string> stk;
        for(int i=tokens.size()-1; i>=0; i--)
        {
            stk.push(tokens[i]);
        }
        
        vector<long long int> v;
        while(!stk.empty())
        {
            if(stk.top() != "+" && stk.top() != "-" && stk.top() != "*" && stk.top() != "/")
            {
                v.push_back(stoll(stk.top()));
            }
            
            else
            {
                long long int x = v.back();
                v.pop_back();
                long long int y = v.back();
                v.pop_back();
                
                long long int ans = 0;
                if(stk.top() == "+")
                    ans = y + x;
                else if(stk.top() == "-")
                    ans = y - x;
                else if(stk.top() == "*")
                    ans = y * x;
                else if(stk.top() == "/")
                    ans = y / x;
                
                v.push_back(ans);
            }
            
            stk.pop();
        }
        
        return v[0];
    }
};