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
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
     {
        vector<pair<int, int>> adj[N];
        for(int i=0; i<M; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        stack<int> stk;
        vector<int> dis(N), visited(N);
        
        for(int i=0; i<N; i++)
	    {
	        if(visited[i] == 0)
	        {
	            dfs(i, N, adj, stk, visited);
	        }
	    }
	    
	    for(int i=0; i<N; i++)
	    {
	        dis[i] = 1e9;
	    }
	    
	    dis[0] = 0;
	    while(!stk.empty())
	    {
	        int node = stk.top();
	        stk.pop();
	        for(auto x : adj[node])
	        {
	            if(dis[node] + x.second < dis[x.first])
	            {
	                dis[x.first] = dis[node] + x.second;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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