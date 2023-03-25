class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& visited, vector<vector<char>> grid) 
    {
        visited[i][j] = 1;
        
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i, j});
        
        vector<int> delmat = {-1, 0, 1, 0, -1};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int nrow = row + delmat[i];
                int ncol = col + delmat[i+1];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        int ctr = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    ctr++;
                    bfs(i, j, visited, grid);
                }
            }
        }
        
        return ctr;
    }
    
};