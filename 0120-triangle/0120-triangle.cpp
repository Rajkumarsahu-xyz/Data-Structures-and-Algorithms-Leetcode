class Solution {
public:
    
    int total(vector<vector<int>>& triangle, int m)
    {
        vector<vector<int>> dp(m, vector<int> (m, -1));
        for(int j=0;j<m;j++)
        {
            dp[m-1][j] = triangle[m-1][j];
        }
        
        for(int i=m-2; i>=0; i--)
        {
            for(int j=i; j>=0; j--)
            {
                int diagonalsum = triangle[i][j] + dp[i+1][j+1];
                int downsum = triangle[i][j] + dp[i+1][j];
                
                dp[i][j] = min(diagonalsum, downsum);
            }
        }
        
        return dp[0][0];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();
        return total(triangle, m);
    }
};