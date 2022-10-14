class Solution {
public:
    
    int paths(int m, int n, vector<vector<int>>& dp)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0  &&  j==0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                
                int right=0;
                int bottom=0;
                
                if(i>0) 
                    bottom = dp[i-1][j];
                if(j>0)
                    right = dp[i][j-1];
                
                dp[i][j] = right + bottom;
            }
        }
        
        return dp[m-1][n-1];
    }
    
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return paths(m, n, dp);
    }
};