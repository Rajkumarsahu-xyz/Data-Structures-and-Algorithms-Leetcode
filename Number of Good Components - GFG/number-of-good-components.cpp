//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    void dfs(vector<vector<int>>& adj, int node, vector<int>& visited, int &ctr)
    {
        visited[node] = 1;
        ctr++;
        for(auto x : adj[node])
        {
            if(!visited[x])
            {
                dfs(adj, x, visited, ctr);
            }
        }
    }
    
    bool inout(vector<vector<int>> &adjlist, int ctr, int n, int start)
    {
        // vector<int> iN(n+1,0);
        
        // iN[start] = adjlist[start].size();
        
        if(adjlist[start].size() != ctr-1)
        return false;
        
        for(auto x : adjlist[start])
        {
            // iN[x] = adjlist[x].size();
            if(adjlist[x].size() != ctr-1)
            return false;
        }
        
        // for(int i = 1; i <= n; i++)
        // {
        //     if((iN[i]!=ctr-1 && iN[i]!=0))
        //     {
        //         return false;
        //     }
        // }
        
        // for(auto x : adjlist[start])
        // {
        //     if()
        // }
        
        return true;
    }
  
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) 
    {
        vector<int> visited(V+1);
        
        int edges = 0;
        for(int i=1; i<=V; i++)
        {
            if(!visited[i])
            {
                int ctr = 0;
                dfs(adj, i, visited, ctr);
                if(inout(adj, ctr, V, i))
                {
                    edges++;
                }
            }
        }
        
        return edges;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends