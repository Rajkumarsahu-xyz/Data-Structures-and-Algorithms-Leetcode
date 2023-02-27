class Solution {
public:
    
    bool lcs(string &word1, string &word2, int n1, int n2, vector<vector<int>>& dp)
    {
        if(n1 < 0  &&  n2 < 0)
            return true;
        
        if(n1<0)
        {
            // return 0;
            // return (word2[n2] == '*' && lcs(word1, word2, n1, n2-1, dp));
            while(n2 >= 0)
            {
                if(word2[n2] != '*')
                    return false;
                n2--;
            }
            return 1;
        }
        
        if(n2<0) return 0;
        
        if(n1>=0 && dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }
        
        bool notTake = false, one=false, two=false, three=false;
        
        if(word2[n2]=='?' || (n1>=0 && word1[n1] == word2[n2]))
            return dp[n1][n2] = lcs(word1, word2, n1-1, n2-1, dp);
        
        else if(word2[n2] == '*')
        {
            one = lcs(word1, word2, n1, n2-1, dp);
            two = lcs(word1, word2, n1-1, n2, dp);
            three = lcs(word1, word2, n1-1, n2-1, dp);
            
            notTake = (one || two || three);
        }
        if(n1<0) return notTake;
        return dp[n1][n2] = notTake;
        
    }
    
    bool isMatch(string s, string p) 
    {
        int n1 = s.length(), n2 = p.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return lcs(s, p, n1-1, n2-1, dp);
        
    }
};