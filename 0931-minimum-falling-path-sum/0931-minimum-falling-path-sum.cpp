class Solution {
public:
    int minPathSum(vector<vector<int>>& matrix, int i, int j, int n, vector<vector<int>>& dp)
    {
        if(j<0 || j>n)
            return 1e9;
        if(i==n)
            return matrix[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 1e9;
        for(int k=-1; k<=1; k++)
        {
            ans = min(ans, matrix[i][j] + minPathSum(matrix, i+1, j+k, n, dp));
        }
        
        return dp[i][j] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int i=0, ans=1e9;
        for(int j=0; j<n; j++)
        {
            vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
            ans = min(ans, minPathSum(matrix, i, j, n-1, dp));
        }
        return ans;
    }
};