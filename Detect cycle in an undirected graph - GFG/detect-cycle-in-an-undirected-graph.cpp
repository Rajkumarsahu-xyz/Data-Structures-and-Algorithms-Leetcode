//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool bfs(vector<int> adj[], vector<int> &visited, vector<int> &parent, int i)
    {
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            for(auto x : adj[t])
            {
                if(parent[t]!=x && visited[x]==1)
                {
                    return true;
                }
                
                else if(!visited[x])
                {
                    parent[x] = t;
                    visited[x] = 1;
                    q.push(x);
                }
            }
        }
        return false;
        
    }
    
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int> visited(V), parent(V, -1);
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                bool f = bfs(adj, visited, parent, i);
                if(f == true)
                    return true;
            }
        }
        
        
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends