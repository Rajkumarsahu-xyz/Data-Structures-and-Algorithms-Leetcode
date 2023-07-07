class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        // vector<vector<int>> visited(m, vector<int>(n));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                }
            }
        
        }
        
        vector<int> dir = {-1, 0, 1, 0, -1};
        int ans = 0;
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int minutes = q.front().second;
            ans = max(ans, minutes);
            
            q.pop();
            int nx, ny;
            for(int i=0; i<4; i++)
            {
                nx = x+dir[i];
                ny = y+dir[i+1];
                
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1)
                {
                    grid[nx][ny] = 2;
                    
                    q.push({{nx, ny}, minutes+1});
                }
                    
            }
            
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return ans;
        
    }
};