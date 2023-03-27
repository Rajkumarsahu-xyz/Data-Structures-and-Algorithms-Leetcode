//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pi pair<int, pair<int, int>>

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pi, vector<pi>, greater<pi>> pq; // {wt, {node, parent}}
        pq.push({0, {0, -1}});
        
        vector<int> visited(V, 0);
        vector<pair<int, int>> mst;
        
        int sum = 0;
        while(!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            
            if (visited[node] == 1) continue;
            
            visited[node] = 1;
            sum += wt;
            
            if(parent != -1)
            {
                mst.push_back({parent, node});
            }
            for(auto x : adj[node])
            {
                int adjnode = x[0];
                int nwt = x[1];
                if(!visited[adjnode])
                {
                    pq.push({nwt, {adjnode, node}});
                }
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends