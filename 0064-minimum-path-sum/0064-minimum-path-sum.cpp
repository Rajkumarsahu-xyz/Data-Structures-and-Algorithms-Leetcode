class Solution {
public:
    
    int pathSum(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == 0  &&  j == 0)
                   dp[0][0] = grid[0][0];
                
                else
                {
                    int upsum = grid[i][j];
                    if(i>0) upsum += dp[i-1][j];
                    else upsum += 1e9;
                
                    int leftsum = grid[i][j];
                    if(j>0) leftsum +=dp[i][j-1];
                    else leftsum += 1e9;
                
                    dp[i][j] = min(upsum , leftsum);
                }
            }
        }
        
        return dp[m-1][n-1];
    }
    
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return pathSum(m, n, grid, dp);
    }
};