#define pi pair<int, pair<int, int>>

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n = heights.size(), m = heights[0].size();
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({heights[0][0], {0, 0}});
        
        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        distance[0][0] = 0;
        pq.push({0, {0, 0}});
        
        vector<int> delmat = {-1, 0, 1, 0, -1};
        
        while(!pq.empty())
        {
            int effort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            if(x == n-1  &&  y == m-1)
                return effort;
            
            for(int i=0; i<4; i++)
            {
                int x1 = x + delmat[i];
                int y1 = y + delmat[i+1];
                
                if(x1>=0 && y1>=0 && x1<n && y1<m)
                {
                    int neweffort = max(abs(heights[x1][y1] - heights[x][y]), effort);
                    
                    if(neweffort < distance[x1][y1])
                    {
                        distance[x1][y1] = neweffort;
                        pq.push({neweffort, {x1, y1}});
                    }
                }
            }
        }
        
        return -1;
    }
};