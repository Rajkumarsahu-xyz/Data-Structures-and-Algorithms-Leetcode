class Solution {
public:
    
    // int dp[1001][1001];
    int subsequences(string &text1, string &text2, int m, int n, vector<vector<int>>& dp)
    {
        if(m == 0 || n == 0)
            return 0;
        
        if(text1[m-1] == text2[n-1])
            return dp[m][n] = 1 + subsequences(text1, text2, m-1, n-1, dp);
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        return dp[m][n] = max(subsequences(text1, text2, m-1, n, dp), subsequences(text1, text2, m, n-1, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return subsequences(text1, text2, m, n, dp);
    }
};