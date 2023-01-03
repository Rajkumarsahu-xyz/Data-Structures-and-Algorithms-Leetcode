class Solution {
public:
    
    void dfs(vector<int> adjlist[], int node, vector<int>& visited, vector<int>& ans)
    {
        visited[node] = 1;
        ans.push_back(node);
        for(auto x : adjlist[node])
        {
            if(!visited[x])
            {
                dfs(adjlist, x, visited, ans);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int V = isConnected.size();
        vector<int> ans, visited(V, 0);
        vector<int> adjlist[V];
        
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        
        int ctr = 0;
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                ctr++;
                dfs(adjlist, i, visited, ans);
            }
        }
        return ctr;
    }
};