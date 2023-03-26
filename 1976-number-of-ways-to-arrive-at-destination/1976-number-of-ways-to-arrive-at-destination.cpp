#define pi pair<long long, long long>


class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<pair<long long, long long>> adjlist[n];
        for(int i=0; i<roads.size(); i++)
        {
            adjlist[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adjlist[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        priority_queue<pi, vector<pi>, greater<pi>> pq; // {time, node}
        vector<long long> time(n, 1e18), ways(n, 0);
        
        time[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        while(!pq.empty())
        {
            long long t = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            
            for(auto x : adjlist[node])
            {
                long long adjnode = x.first;
                long long nt = x.second;
                
                if (t+nt < time[adjnode])
                {
                    time[adjnode] = t + nt;
                    pq.push({t+nt, adjnode});
                    ways[adjnode] = ways[node];
                }
                
                else if (t+nt == time[adjnode])
                {
                    ways[adjnode] = (ways[adjnode]+ways[node]) % (1000000007);
                }
            }
            
        }
        
        cout << ways[n-1] << endl;
        return ways[n-1] % (1000000007);
    }
    
};