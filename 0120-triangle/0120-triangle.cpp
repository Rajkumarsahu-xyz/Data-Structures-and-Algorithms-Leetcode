class Solution {
public:
    
    int total(vector<vector<int>>& triangle, int m)
    {
        vector<int> prev(m, -1);
        for(int j=0; j<m; j++)
        {
            prev[j] = triangle[m-1][j];
        }
        
        for(int i=m-2; i>=0; i--)
        {
            vector<int> curr(m, -1);
            for(int j=i; j>=0; j--)
            {
                int diagonalsum = triangle[i][j] + prev[j+1];
                int downsum = triangle[i][j] + prev[j];
                
                curr[j] = min(diagonalsum, downsum);
            }
            prev = curr;
        }
        
        return prev[0];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();
        return total(triangle, m);
    }
};