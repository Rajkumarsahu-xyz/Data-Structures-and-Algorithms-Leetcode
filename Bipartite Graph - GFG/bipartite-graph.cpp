//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node, int color, vector<int>& colored, vector<int> adj[])
    {
        colored[node] = color;
        
        for(auto x : adj[node])
        {
            if(colored[x] == -1)
            {
                if(!dfs(x, !color, colored, adj))
                    return false;
            }
            
            else if(colored[x] == color)
                return false;
        }
        
        return true;
    }
    
    
    bool isBipartite(int n, vector<int>adj[]) 
    {
        vector<int> colored(n, -1);
        
        //colored[0] = 0;
        for(int i=0; i<n; i++)
        {
            if(colored[i] == -1)
            {
                if(!dfs(i, 0, colored, adj))
                    return false;
            }
        }
        
        return true;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends