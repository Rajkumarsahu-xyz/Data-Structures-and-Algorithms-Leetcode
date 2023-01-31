//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int start, int V, vector<pair<int, int>> adj[], stack<int>& stk, vector<int>& visited)
	{
	    visited[start] = 1;
	    for(auto x : adj[start])
	    {
	        if(visited[x.first] == 0)
	        {
	            dfs(x.first, V, adj, stk, visited);
	        }
	    }
	    
	    stk.push(start);
	}
  
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
    {
        vector<int> adj[N];
        for(auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
	    vector<int> dis(N);
	    for(int i=0; i<N; i++)
	    {
	        dis[i] = 1e9;
	    }
	    
	    dis[src] = 0; 
        queue<int> q;
        q.push(src); 
        while(!q.empty()) 
        {
            int node = q.front();
            q.pop(); 
            for(auto x : adj[node]) 
            {
                if(dis[node] + 1 < dis[x]) 
                {
                    dis[x] = 1 + dis[node]; 
                    q.push(x); 
                }
            }
        }
	    
	    for(int i=0; i<dis.size(); i++)
	    {
	        if(dis[i] == 1e9) dis[i] = -1;
	    }
        
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends