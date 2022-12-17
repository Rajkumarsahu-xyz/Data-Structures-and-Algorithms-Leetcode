class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        unordered_map<string, function<long long int (long long int, long long int) > > map = {
            { "+" , [] (long long int a, long long int b) { return a + b; } },
            { "-" , [] (long long int a, long long int b) { return a - b; } },
            { "*" , [] (long long int a, long long int b) { return a * b; } },
            { "/" , [] (long long int a, long long int b) { return a / b; } }
        };
        
        stack<long long int> stk;
        for (string& s : tokens) 
        {
            if (!map.count(s)) 
            {
                stk.push(stoll(s));
            } 
            else 
            {
                long long int op1 = stk.top();
                stk.pop();
                long long int op2 = stk.top();
                stk.pop();
                stk.push(map[s](op2, op1));
            }
        }
        
        return stk.top();
    }
};