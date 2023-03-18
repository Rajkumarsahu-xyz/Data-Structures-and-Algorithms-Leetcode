//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pi pair<int, int>

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges)
    {
        vector<vector<int>> adj[n+1];
        for(int i=0; i<m; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<int> distance(n+1, 1e9);
        distance[1] = 0;
        vector<int> parent(n+1);
        for(int i=0; i<n+1; i++)
        {
            parent[i] = i;
        }
        pq.push({0, 1});
        
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto x : adj[node])
            {
                int adjNode = x[0];
                int edgeWeight = x[1];
                
                if(dis+edgeWeight < distance[adjNode])
                {
                    distance[adjNode] = dis+edgeWeight;
                    pq.push({distance[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        int flag = -1;
        for(int i=0; i<parent.size(); i++)
        {
            if(i!=1 && parent[i] == 1)
            {
                flag = 0;
                break;
            }
            // cout << parent[i] <<  " ";
        }
        // cout << endl;
        if(flag == -1) return {-1};
        
        vector<int> ans;
        int i = n;
        ans.push_back(n);
        while(parent[i] != 1)
        {
            if(parent[i] == i)
                return {-1};
            ans.push_back(parent[i]);
            i = parent[i];
        }
        
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends