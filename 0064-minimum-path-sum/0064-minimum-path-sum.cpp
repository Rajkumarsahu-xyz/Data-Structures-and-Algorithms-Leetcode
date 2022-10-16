class Solution {
public:
    
    int pathSum(int m, int n, vector<vector<int>>& grid, vector<int>& prev)
    {
        for(int i=0; i<m; i++)
        {
            vector<int> curr(n, -1);
            for(int j=0; j<n; j++)
            {
                if(i == 0  &&  j == 0)
                   curr[0] = grid[0][0];
                
                else
                {
                    int upsum = grid[i][j];
                    if(i>0) upsum += prev[j];
                    else upsum += 1e9;
                
                    int leftsum = grid[i][j];
                    if(j>0) leftsum += curr[j-1];
                    else leftsum += 1e9;
                
                    curr[j] = min(upsum , leftsum);
                }
            }
            
            prev = curr;
        }
        
        return prev[n-1];
    }
    
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> prev(n, -1);
        return pathSum(m, n, grid, prev);
    }
};