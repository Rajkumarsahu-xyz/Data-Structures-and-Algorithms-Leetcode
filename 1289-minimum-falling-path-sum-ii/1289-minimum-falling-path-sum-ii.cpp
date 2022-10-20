class Solution {
public:
    
    int fallingPathSum(vector<vector<int>>& matrix, int n, int i, int j)
    {
        vector<int> prev(n, -1);
        for(int j = 0; j < n; j++)
            prev[j] = matrix[n-1][j];
        
        for(int i=n-2; i>=0; i--)
        {
            vector<int> curr(n, -1);
            for(int j=n-1; j>=0; j--)
            {
                int ans = INT_MAX;
                for(int k=n-1; k>=0; k--)
                {
                    if(k != j)
                        ans = min(ans, prev[k]+matrix[i][j]);
                }
                
                curr[j] = ans;
            }
            prev = curr;
        }
        
        return *min_element(prev.begin(), prev.end());
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int i=0, j=0;
        
        return fallingPathSum(matrix, n, i, j);
        
    }
};