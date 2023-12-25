class Solution {
public:
    //vector<int> dp(101, -1);
    int decode(string &s, int i, int ctr, vector<int>& dp)
    {
        if(s.length() <= i)
        {
            return 1;
        }
        
        if(dp[i] != -1)
            return dp[i];
        
        if(s[i] == '0')
            return dp[i] = 0;
        
        else
            ctr += decode(s, i+1, ctr, dp);
        
        if(i+1 < s.length())
        {
            int d = (s[i]-'0')*10 + (s[i+1]-'0');
            if(d <= 26)
            {
                if(dp[i] != -1)
                    return dp[i];
                else
                    ctr += decode(s, i+2, ctr, dp);
            }
            else
                return dp[i] = ctr;
        }
        
        return dp[i] = ctr;
    }
    
    
    int numDecodings(string s) 
    {
        int ctr=0;
        int i = 0;
        vector<int> dp(s.length()+1, -1);
        return decode(s, i, ctr, dp);
    }
};