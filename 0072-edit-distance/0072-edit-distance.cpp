class Solution {
public:
    
    int lcs(string word1, string word2, int n1, int n2, vector<vector<int>>& dp)
    {
        if(n1 < 0)
            return n2+1;
        else if(n2 < 0)
            return n1+1;
        
        if(dp[n1][n2] != -1)
            return dp[n1][n2];
        
        int take = 0, notTake = 0;
        
        if(word1[n1] == word2[n2])
            take = lcs(word1, word2, n1-1, n2-1, dp);
        else
            notTake = 1 + min({lcs(word1, word2, n1-1, n2, dp), lcs(word1, word2, n1, n2-1, dp), lcs(word1, word2, n1-1, n2-1, dp)});
        
        return dp[n1][n2] = take + notTake;
    }
    
    
    int minDistance(string word1, string word2) 
    {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return lcs(word1, word2, n1-1, n2-1, dp);
    }
};