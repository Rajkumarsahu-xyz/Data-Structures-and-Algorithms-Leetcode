#define pi pair<int, pair<int, int>>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int, int>> adjlist[n];
        for(int i=0; i<flights.size(); i++)
        {
            adjlist[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        
        priority_queue<pi, vector<pi>, greater<pi>> pq; // {stops, {node, distance covered}}
        vector<int> distance(n+1, 1e9);
        distance[src] = 0;
        pq.push({0, {src, 0}});
        
        while(!pq.empty())
        {
            int stops = pq.top().first;
            int city = pq.top().second.first;
            int dis_till_now = pq.top().second.second;
            pq.pop();
            
            if(stops > k)
                continue;
            
            for(auto x : adjlist[city])
            {
                int adjcity = x.first;
                int dis_to_city = x.second;
                
                if(dis_till_now + dis_to_city  <  distance[adjcity])
                {
                    distance[adjcity] = dis_till_now + dis_to_city;
                    pq.push({stops+1, {adjcity, distance[adjcity]}});
                }
            }
        }
        
        if (distance[dst] == 1e9)
            return -1;
        
        return distance[dst];
    }
};