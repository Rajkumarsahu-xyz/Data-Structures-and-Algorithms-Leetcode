#define pi pair<int, pair<int, int>>

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
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({1, {0, 0}});
        int destx = n-1;
        int desty = n-1;
        
        vector<int> del = {-1, -1, 0, 1, 1, 0, -1, 1, -1};
        while(!pq.empty())
        {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int dis = pq.top().first;
            pq.pop();
            
            for(int i=0; i<8; i++)
            {
                int x1 = x + del[i];
                int y1 = y + del[i+1];
                
                if(x1>=0 && x1<n && y1>=0 && y1<n && grid[x1][y1]==0)
                {
                    if(x1 ==  destx  &&  y1 == desty)
                        return dis+1;
                    grid[x1][y1] = 1;
                    pq.push({dis+1, {x1, y1}});
                }
            }
        }
        
        return -1;
    }
};