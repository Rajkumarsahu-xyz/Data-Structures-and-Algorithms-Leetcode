//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // bool dfs(int start, int V, vector<int> adj[], vector<int>& visited, vector<int>& path_visited)
    // {
    //     visited[start] = 1;
    //     path_visited[start] = 1;
        
    //     for(auto x : adj[start])
    //     {
    //         if(visited[x] == 0)
    //         {
    //             if(dfs(x, V, adj, visited, path_visited) == true)
    //             return true;
    //         }
            
    //         else if(path_visited[x] == 1)
    //         {
    //             return true;
    //         }
    //     }
        
    //     path_visited[start] = 0;
    //     return false;
    // }
    
    bool isCyclic(int n, vector<int> adj[]) 
    {
        vector<int> ans, indegree(n);
	    queue<int> q;
	    for(int i=0; i<n; i++)
	    {
	        for(auto &x : adj[i])
	        {
	            indegree[x]++;
	        }
	    }
	    
	    for(int i=0; i<n; i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto &x : adj[node])
	        {
	            indegree[x]--;
	            if(indegree[x] == 0) q.push(x);
	        }
	    }
	    
	    return !(ans.size() == n);
        
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends