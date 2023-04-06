class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int n, int m)
    {
        grid[i][j] = -1;
        vector<int> del = {-1, 0, 1, 0, -1};
        for(int k=0; k<4; k++)
        {
            int ni = i + del[k];
            int nj = j + del[k+1];
            
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj] == 0)
                dfs(ni, nj, grid, n, m);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++)
        {
            if(grid[i][0] == 0)
            {
                dfs(i, 0, grid, n, m);
            }
            if(grid[i][m-1] == 0)
            {
                dfs(i, m-1, grid, n, m);
            }
        }
        
        // for(int i=0; i<n; i++)
        // {
        //     if(grid[i][m-1] == 0)
        //     {
        //         dfs(i, m-1, grid, n, m);
        //     }
        // }
        
        for(int j=0; j<m; j++)
        {
            if(grid[0][j] == 0)
            {
                dfs(0, j, grid, n, m);
            }
            if(grid[n-1][j] == 0)
            {
                dfs(n-1, j, grid, n, m);
            }
        }
        
        // for(int j=0; j<m; j++)
        // {
        //     if(grid[n-1][j] == 0)
        //     {
        //         dfs(n-1, j, grid, n, m);
        //     }
        // }
        
        int ctr = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 0)
                {
                    ctr++;
                    dfs(i, j, grid, n, m);
                }
            }
        }
        
        return ctr;
        
    }
};