class Solution {
public:
    
    int fallingPathSum(vector<vector<int>>& matrix, int n, vector<vector<int>>& dp)
    {
//         if(j < 0  ||  j > n)
//             return 1e9;
        
//         if(i==n)
//             return matrix[i][j];
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         int downsum = matrix[i][j] + fallingPathSum(matrix, n, i+1, j, dp);
//         int leftdgsum = matrix[i][j] + fallingPathSum(matrix, n, i+1, j-1, dp); 
//         int rightdgsum = matrix[i][j] + fallingPathSum(matrix, n, i+1, j+1, dp);
        
//         return dp[i][j] = min(downsum, min(rightdgsum, leftdgsum));
        
        for(int j=0; j<n; j++)
        {
            dp[n-1][j] = matrix[n-1][j];
        }
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                int downsum = matrix[i][j] + dp[i+1][j];
                
                int leftdgsum = matrix[i][j];
                if(j-1>=0)
                    leftdgsum += dp[i+1][j-1];
                else
                    leftdgsum += 1e9;
                
                int rightdgsum = matrix[i][j];
                if(j+1<=n-1)
                    rightdgsum += dp[i+1][j+1];
                else
                    rightdgsum += 1e9;
                
                dp[i][j] = min(downsum, min(rightdgsum, leftdgsum));
            }
        }
        
        int ans = INT_MAX;
    
        for(int j=0; j<n;j++)
        {
            ans = min(ans,dp[0][j]);
        }
        
        return ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int i=0, ans = INT_MAX;
        
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fallingPathSum(matrix, n, dp);
        
    }
};