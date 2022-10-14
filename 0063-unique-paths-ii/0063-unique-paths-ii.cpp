class Solution {
public:
    
    int paths(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        if(m==0  &&  n==0)
            return 1;
        
        if(m<0  ||  n<0)
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        int right=0;
        int bottom=0;
        
        if(m>0  &&  obstacleGrid[m-1][n] != 1)
            right = paths(m-1, n, obstacleGrid, dp);
        if(n>0  &&  obstacleGrid[m][n-1] != 1)
            bottom = paths(m, n-1, obstacleGrid, dp);
        
        return dp[m][n] = right+bottom;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1) 
            return 0;
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return paths(m-1, n-1, obstacleGrid, dp);
    }
};