//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int start, int V, vector<int> adj[], stack<int>& stk, vector<int>& visited)
	{
	    visited[start] = 1;
	    for(auto x : adj[start])
	    {
	        if(visited[x] == 0)
	        {
	            dfs(x, V, adj, stk, visited);
	        }
	    }
	    
	    stk.push(start);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> topo, visited(V);
	    stack<int> stk;
	    
	    for(int i=0; i<V; i++)
	    {
	        if(visited[i] == 0)
	        {
	            dfs(i, V, adj, stk, visited);
	        }
	    }
	    
	    while(!stk.empty())
	    {
	        topo.push_back(stk.top());
	        stk.pop();
	    }
	    
	    return topo;
	}
};


// class Solution
// {
// 	public:
// 	//Function to return list containing vertices in Topological order. 
// // 	void dfs(int start, int V, vector<int> adj[], stack<int>& stk, vector<int>& visited)
// // 	{
// // 	    visited[start] = 1;
// // 	    for(auto x : adj[start])
// // 	    {
// // 	        if(visited[x] == 0)
// // 	        {
// // 	            dfs(x, V, adj, stk, visited);
// // 	        }
// // 	    }
	    
// // 	    stk.push(start);
// // 	}
	
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    vector<int> kahn, indegree(V);
// 	    queue<int> q;
// 	    for(int i=0; i<V; i++)
// 	    {
// 	        for(auto x : adj[i])
// 	        {
// 	            indegree[x]++;
// 	        }
// 	    }
	    
// 	    for(int i=0; i<V; i++)
// 	    {
// 	        if(indegree[i] == 0)
// 	        {
// 	            q.push(i);
// 	        }
// 	    }
	    
// 	    while(!q.empty())
// 	    {
// 	        int node = q.front();
// 	        q.pop();
// 	        kahn.push_back(node);
// 	        for(auto x : adj[node])
// 	        {
// 	            indegree[x]--;
// 	            if(indegree[x] == 0) q.push(x);
// 	        }
// 	    }
	    
// 	    return kahn;
// 	}
// };

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends