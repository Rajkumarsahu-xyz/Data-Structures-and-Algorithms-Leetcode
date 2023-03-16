//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int src, vector<int> adj[], vector<int> visited, int parent)
    {
        visited[src] = 1;
        for(auto x : adj[src])
        {
            if(visited[x] == 1  &&  parent != x)
            {
                return true;
            }
            else if(parent != x)
            {
                visited[x] = 1;
                if(dfs(x, adj, visited, src)) return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        int parent = -1;
        vector<int> visited(V);
        for(int i = 0;i<V;i++) 
        {
            if(!visited[i]) 
            {
                if(dfs(i, adj, visited, parent)) 
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