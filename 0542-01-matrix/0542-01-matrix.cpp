class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m=grid[0].size();
	    vector<vector<int>> distance(n, vector<int>(m, 0)), visited(n, vector<int>(m, 0));
	    queue<pair<pair<int, int>, int>> q;
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            if(grid[i][j] == 0)
	            {
	                q.push({{i, j}, 0});
	                distance[i][j] = 0;
	                visited[i][j] = 1;
	            }
	        }
	    }
	    
	    int delrow[] = {0, 0, -1, 1}; 
	    int delcol[] = {-1, 1, 0, 0};
	    
	    while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            distance[r][c] = dis;
            
            q.pop();
            for(int i=0; i<4; i++)
            {
                int row = r + delrow[i];
                int col = c + delcol[i];
                
                if(row>=0 && row<n && col>=0 && col<m && visited[row][col]==0 && grid[row][col]==1)
                {
                    visited[row][col] = 1;
	                q.push({{row, col}, dis+1});
                }
            }
        }
	    
	    return distance;
    }
};