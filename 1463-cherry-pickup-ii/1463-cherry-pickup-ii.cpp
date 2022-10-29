class Solution {
public:
    
    int maxcherry(vector<vector<int>> &grid, int r, int c, int i, int j1, int j2, vector<vector<vector<int>>>& dp)
    {
        if(j1<0 || j1>c-1 || j2<0 || j2>c-1)
            return -1e9;   
        if(i == r-1)
        {
            if(j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
    
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        int ans = INT_MIN;
        for(int dj1=-1; dj1<=1; dj1++)
        {
            for(int dj2=-1; dj2<=1; dj2++)
            {
                if(j1 == j2)
                    ans = max(ans, grid[i][j1] + maxcherry(grid, r, c, i+1, j1+dj1, j2+dj2, dp));
                else
                    ans = max(ans, grid[i][j1] + grid[i][j2] + maxcherry(grid, r, c, i+1, j1+dj1, j2+dj2, dp));
            }
        }
    
        return dp[i][j1][j2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) 
    {
        int r=grid.size(), c=grid[0].size(); 
        int i=0, j1=0, j2=c-1;
        vector<vector<vector<int>>> dp(r+1, vector<vector<int>>(c+1, vector<int> (c+1, -1)));
        return maxcherry(grid, r, c, i, j1, j2, dp);
    }
    
};