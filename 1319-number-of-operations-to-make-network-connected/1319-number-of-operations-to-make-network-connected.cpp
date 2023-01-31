class Solution {
public:
    
    void dfs(int start, int n, vector<int> adj[], vector<int>& visited)
    {
        visited[start] = 1;
        for(auto x : adj[start])
        {
            if(visited[x] == 0)
            {
                dfs(x, n, adj, visited);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if(connections.size() < n-1)
            return -1;
        vector<int> adj[n];
        for(int i=0; i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<int> visited(n);
        int ctr = 0;
        for(int i=0; i<n; i++)
        {
            if(visited[i] == 0)
            {
                ctr++;
                dfs(i, n, adj, visited);
            }
        }
        
        return ctr-1;
    }
};