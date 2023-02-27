class Solution {
public:
    
    bool lcs(string &word1, string &word2, int n1, int n2, vector<vector<bool>>& dp)
    {
        dp[0][0] = true;
        
        for (int i=0; i<word2.size()  &&  word2[i]=='*'; i++)
        {
            dp[0][i+1] = true;
        }
        
        
        for(int i=1; i<=n1; i++)
        {
            for(int j=1; j<=n2; j++)
            {
                if(word1[i-1] == word2[j-1] || word2[j-1]=='?')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                
                else if(word2[j-1] == '*')
                {
                    dp[i][j] = (dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1]);
                }
            }
        }
        
        return dp[n1][n2];
        
        
//         if(n1 < 0  &&  n2 < 0)
//             return true;
        
//         else if(n1 < 0)
//         {
//             while(n2 >= 0)
//             {
//                 if(word2[n2] != '*')
//                     return false;
//                 n2--;
//             }
//             return true;
//         }
        
//         else if(n2 < 0)
//         {
//             return false;
//         }
        
//         if(dp[n1][n2] != -1)
//             return dp[n1][n2];
        
//         bool take = false, notTake = false;
        
//         if(word1[n1] == word2[n2] || word2[n2]=='?')
//             take = lcs(word1, word2, n1-1, n2-1, dp);
        
//         else
//         {
//             if(word2[n2] == '*')
//                 notTake = (lcs(word1, word2, n1-1, n2, dp) || lcs(word1, word2, n1, n2-1, dp) || lcs(word1, word2, n1-1, n2-1, dp));
//         }
        
//         return dp[n1][n2] = take || notTake;
    }
    
    bool isMatch(string s, string p) 
    {
        int n1 = s.length(), n2 = p.length();
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        return lcs(s, p, n1, n2, dp);
        
    }
};


