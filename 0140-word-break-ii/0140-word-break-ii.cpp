class Solution {
public:
    
    bool wordbrk(string s, int n, int i, unordered_set<string>& st, string p, vector<string> &res)
    {
        if(i == n)
        {
            p.pop_back();
            res.push_back(p);
            return true;
        }
        
        // if(dp[i] != -1)
        //     return dp[i];
        
        bool ans = false;
        for(int j=1; j<=s.length()-i; j++)
        {
            string t = s.substr(i, j);
            // cout << t << " raj" << endl;
            int k = p.length();
            if(st.find(t) != st.end())
            {
                p = p + t + " " ;
                // cout << p << endl;
                // cout << i << " " << j << endl;
                ans |= wordbrk(s, n, i+j, st, p, res);
                p = p.substr(0, k);
                // cout << p << endl;
            }
        }
        
        return ans;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.length();
        unordered_set<string> st;
        for(int i=0; i<wordDict.size(); i++)
        {
            st.insert(wordDict[i]);
        }
        
        vector<int> dp(n+1, -1);
        vector<string> res;
        wordbrk(s, n, 0, st, "", res);
        
        return res;
    }
};