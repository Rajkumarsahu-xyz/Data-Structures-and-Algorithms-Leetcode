#define pi pair<int, int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int, int>> adjlist[n+1];
        for(int i=0; i<times.size(); i++)
        {
            adjlist[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        priority_queue<pi, vector<pi>, greater<pi>> pq; // {time, node}
        pq.push({0, k});
        vector<int> timing(n+1, 1e9);
        timing[k] = 0;
        
        int ans = INT_MIN;
        while(!pq.empty())
        {
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto x : adjlist[node])
            {
                int adjnode = x.first;
                int newt = x.second;
                
                if(t+newt < timing[adjnode])
                {
                    timing[adjnode] = t+newt;
                    pq.push({t+newt, adjnode});
                }
            }
        }
        
        for(int i=1; i<n+1; i++)
        {
            ans = max(ans, timing[i]);
            if(timing[i] == 1e9)
                return -1;
        }
        
        return ans;
    }
};