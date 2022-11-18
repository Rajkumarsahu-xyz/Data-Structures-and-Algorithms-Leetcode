class Solution {
public:
    
    int lcs(string text1, string text2, int n, int m, vector<vector<int>>& dp)
    {
        for(int i=0; i<=n; i++)
            dp[i][0] = 0;
        for(int j=0; j<=m; j++)
            dp[0][j] = 0;
        
        for(int n1=1; n1<=n; n1++)
        {
            for(int m1=1; m1<=m; m1++)
            {
                int match=0, notMatch=0;
                if(text1[n1-1] == text2[m1-1])
                    match = 1 + dp[n1-1][m1-1];
                else
                    notMatch = 0 + max(dp[n1-1][m1], dp[n1][m1-1]);
                
                dp[n1][m1] = match + notMatch;
            }
        }
        
        return dp[n][m];
    }
    
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        return lcs(text1, text2, n, m, dp);
    }
};