class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>> q;
        q.push({-grid[0][0], {0, 0}});
        
        grid[0][0]=-1;
        while(q.size()) 
        {
            pair<int, pair<int, int>> tmp = q.top();
            int x = tmp.second.first;
            int y = tmp.second.second;
            
            if(x == n-1 && y == m-1) 
                break;
            q.pop();
            grid[x][y]=-1;
            if((x+1) < n&& grid[x+1][y]!=-1) 
            {
                q.push({(tmp.first-grid[x+1][y]), {x+1, y}});
            }
            if((y+1) < m && grid[x][y+1]!=-1) 
            {
                q.push({(tmp.first-grid[x][y+1]), {x, y+1}});
            }
        }
        
        return -q.top().first;
    }
};