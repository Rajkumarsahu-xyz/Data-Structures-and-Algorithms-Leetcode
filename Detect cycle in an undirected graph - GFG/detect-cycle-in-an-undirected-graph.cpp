//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool detect(int src, vector<int> adj[], vector<int> visited, queue<pair<int, int>> q)
    {
        visited[src] = 1;
        q.push({src, -1});
        
        while(!q.empty())
        {
            int node = q.front().first; 
            int parent = q.front().second; 
            q.pop(); 
            for(auto x : adj[node])
            {
                if(visited[x] == 1  &&  parent != x)
                {
                    return true;
                }
                else if(parent != x)
                {
                    visited[x] = 1;
                    q.push({x, node});
                }
            }
            
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        queue<pair<int, int>> q;
        vector<int> visited(V);
        for(int i = 0;i<V;i++) 
        {
            if(!visited[i]) 
            {
                if(detect(i, adj, visited, q)) 
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