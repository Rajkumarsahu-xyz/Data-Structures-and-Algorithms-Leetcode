class Solution {
public:
    
    int total(vector<vector<int>>& triangle, int m, int i, int j, vector<vector<int>>& dp)
    {
        if(dp[i][j]!=-1)
        return dp[i][j];
  
        if(i == m-1) 
            return triangle[i][j];
    
        int downsum = triangle[i][j] + total(triangle, m, i+1, j, dp);
        int diagonalsum = triangle[i][j] + total(triangle, m, i+1, j+1, dp);
  
        return dp[i][j] = min(downsum, diagonalsum);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();
        vector<vector<int>> dp(m+1, vector<int> (m+1, -1));
        int i=0, j=0;
        
        return total(triangle, m, i, j, dp);
    }
};