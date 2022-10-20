class Solution {
public:
    
    int fallingPathSum(vector<vector<int>>& matrix, int n, int i, int j, vector<vector<int>>& dp)
    {   
        for(int j = 0; j < n; j++)
            dp[n-1][j] = matrix[n-1][j];
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                int ans = INT_MAX;
                for(int k=n-1; k>=0; k--)
                {
                    if(k != j)
                        ans = min(ans, dp[i+1][k]+matrix[i][j]);
                }
                
                dp[i][j] = ans;
            }
        }
        
        return *min_element(dp[0].begin(), dp[0].end());
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int i=0, j=0, ans = INT_MAX;
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        ans = min(ans, fallingPathSum(matrix, n, i, j, dp));
        
        return ans;
    }
};