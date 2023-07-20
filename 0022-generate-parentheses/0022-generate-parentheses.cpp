class Solution {
public:
    
    void generate(int open, int close, int n, vector<string> &ans, string s)
    {
        if(open > n)
        {
            return;
        }
        if(open==n && close==n)
        {
            ans.push_back(s);
            return;
        }
        
        if(close < open)
        {
            generate(open, close+1, n, ans, s+')');
            // generate(open+1, close, n, ans, s+'(');
        }
        
        generate(open+1, close, n, ans, s+'(');
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        generate(0, 0, n, ans, "");
        // cout << ans.size() << endl;
        return ans;
    }
};