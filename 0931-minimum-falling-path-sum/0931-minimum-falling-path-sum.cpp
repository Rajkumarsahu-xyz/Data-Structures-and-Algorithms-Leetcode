class Solution {
public:
    
    int fallingPathSum(vector<vector<int>>& matrix, int n, int i, int j, vector<vector<int>>& dp)
    {
        if(j < 0  ||  j > n)
            return 1e9;
        
        if(i==n)
            return matrix[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int downsum = matrix[i][j] + fallingPathSum(matrix, n, i+1, j, dp);
        int leftdgsum = matrix[i][j] + fallingPathSum(matrix, n, i+1, j-1, dp); 
        int rightdgsum = matrix[i][j] + fallingPathSum(matrix, n, i+1, j+1, dp);
        
        return dp[i][j] = min(downsum, min(rightdgsum, leftdgsum));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int i=0, ans = INT_MAX;
        
        for(int j=0; j<n; j++)
        {
            vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
            ans = min(ans, fallingPathSum(matrix, n-1, i, j, dp));
        }
        
        return ans;
    }
};