class Solution {
public:
    
    int total(vector<vector<int>>& triangle, int m, int n, int i, int j, vector<vector<int>>& dp)
    {
        if(i == m)
        {
            return triangle[i][j];
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int diagonalsum = triangle[i][j];
        if(i < m  && j<i+1)
            diagonalsum += total(triangle, m, n, i+1, j+1, dp);
        
        int downsum = triangle[i][j];
        if(i < m)
            downsum += total(triangle, m, n, i+1, j, dp);
        
        return dp[i][j] = min(diagonalsum, downsum);   
    }
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();
        int n = triangle[m-1].size();
        int i=0, j=0;
        
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return total(triangle, m-1, n-1, i, j, dp);
    }
};