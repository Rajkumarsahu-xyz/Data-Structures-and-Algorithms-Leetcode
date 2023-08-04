class Solution {
public:
    bool wordbrk(string s, int n, int i, unordered_set<string>& st, vector<int> &dp)
    {
        if(i == n)
        {
            return true;
        }
        
        if(dp[i] != -1)
            return dp[i];
        
        bool ans = false;
        for(int j=1; j<=s.length()-i; j++)
        {
            string t = s.substr(i, j);
            // cout << t << endl;
            if(st.find(t) != st.end())
                ans |= wordbrk(s, n, i+j, st, dp);
        }
        
        return dp[i] = ans;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.length();
        unordered_set<string> st;
        for(int i=0; i<wordDict.size(); i++)
        {
            st.insert(wordDict[i]);
        }
        
        vector<int> dp(n+1, -1);
        return wordbrk(s, n, 0, st, dp);
    }
};