//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int start, int V, vector<int> adj[], vector<int>& visited, vector<int>& path_visited, vector<int>& check)
    {
        visited[start] = 1;
        path_visited[start] = 1;
        check[start] = 0;
        
        for(auto x : adj[start])
        {
            if(visited[x] == 0)
            {
                if(dfs(x, V, adj, visited, path_visited, check) == true)
                {
                    check[start] = 0;
                    return true;
                }
            }
            
            else if(path_visited[x] == 1)
            {
                check[start] = 0;
                return true;
            }
        }
        
        check[start] = 1;
        path_visited[start] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        vector<int> visited(V), path_visited(V);
        vector<int> check(V);
        vector<int> safe;
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                dfs(i, V, adj, visited, path_visited, check);
            }
        }
        
        for(int i=0; i<V; i++)
        {
            if(check[i]==1) safe.push_back(i);
        }
        
        return safe;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends