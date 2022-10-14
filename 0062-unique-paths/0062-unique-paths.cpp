class Solution {
public:
    
    int paths(int m, int n, vector<vector<int>>& dp)
    {
        if(m < 0  ||  n < 0)
            return 0;
        
        if(m == 0  &&  n == 0)
            return 1;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        int right = paths(m-1, n, dp);
        int bottom = paths(m, n-1, dp);
        
        return dp[m][n] = right + bottom;
    }
    
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return paths(m-1, n-1, dp);
    }
};