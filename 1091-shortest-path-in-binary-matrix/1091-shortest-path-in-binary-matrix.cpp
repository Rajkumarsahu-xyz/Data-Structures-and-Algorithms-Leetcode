class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        if(n == 1)
        {
            if(grid[0][0] == 0)
                return 1;
            else
                return -1;
        }
        
        if(grid[0][0] == 1  ||  grid[n-1][n-1] == 1)
            return -1;
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        int destx = n-1;
        int desty = n-1;
        
        vector<int> del = {-1, -1, 0, 1, 1, 0, -1, 1, -1};
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            
            for(int i=0; i<8; i++)
            {
                int x1 = x + del[i];
                int y1 = y + del[i+1];
                
                if(x1>=0 && x1<n && y1>=0 && y1<n && grid[x1][y1]==0)
                {
                    if(x1 ==  destx  &&  y1 == desty)
                        return dis+1;
                    grid[x1][y1] = 1;
                    q.push({{x1, y1}, dis+1});
                }
            }
        }
        
        return -1;
    }
};