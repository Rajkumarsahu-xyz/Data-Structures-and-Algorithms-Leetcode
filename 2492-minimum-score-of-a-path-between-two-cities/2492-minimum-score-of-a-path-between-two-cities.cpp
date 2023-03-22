class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) 
    {
        vector<vector<int>> adjlist[n+1];
        for(int i=0; i<roads.size(); i++)
        {
            adjlist[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adjlist[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        queue<int> q;
        q.push(1);
        vector<int> visited(n+1, 0);
        visited[1] = 1;
        
        int ans = INT_MAX;
        
        while(!q.empty())
        {
            int city = q.front();
            q.pop();
            
            for(auto x : adjlist[city])
            {
                int city2 = x[0];
                int distance = x[1];
                ans = min(ans, distance);
                if(!visited[city2])
                {
                    q.push(city2);
                    visited[city2] = 1;
                }
            }
        }
        
        return ans;
    }
};