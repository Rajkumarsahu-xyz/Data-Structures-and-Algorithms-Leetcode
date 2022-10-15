class Solution {
public:
    
    int pathSum(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(m == 0  &&  n == 0)
            return grid[m][n];
        
        if(m < 0  ||  n < 0)
            return 1e9;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        int rightsum = grid[m][n] + pathSum(m, n-1, grid, dp);
        int downsum = grid[m][n] + pathSum(m-1, n, grid, dp);
        
        return dp[m][n] = min(rightsum , downsum);
    }
    
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return pathSum(m-1, n-1, grid, dp);
    }
};