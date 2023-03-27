class Solution {
public:
    
    int minpath(vector<vector<int>>& grid, int n, int m, vector<vector<int>> &dp)
    {
        if(n==0 && m==0)
            return grid[0][0];
        if(dp[n][m] != -1)
            return dp[n][m];
        
        int sum = 0;
        int l = 1e9, u = 1e9;
        
        if(n-1>=0)
            u = minpath(grid, n-1, m, dp);
        if(m-1>=0)
            l = minpath(grid, n, m-1, dp);
        sum += (grid[n][m] + min(u, l));
        
        return dp[n][m] = sum;
    }
    
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return minpath(grid, n-1, m-1, dp);
    }
};