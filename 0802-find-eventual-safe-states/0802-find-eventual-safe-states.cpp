class Solution {
public:
    bool dfs(int start, int V, vector<vector<int>>& graph, vector<int>& visited, vector<int>& path_visited, vector<int>& check)
    {
        visited[start] = 1;
        path_visited[start] = 1;
        check[start] = 0;
        
        for(auto x : graph[start])
        {
            if(path_visited[x] == 1)
            {
                check[start] = 0;
                return true;
            }
            if(visited[x] == 0)
            {
                if(dfs(x, V, graph, visited, path_visited, check) == true)
                {
                    check[start] = 0;
                    return true;
                }
            }
            
        }
        
        check[start] = 1;
        path_visited[start] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int V = graph.size();
        vector<int> visited(V), path_visited(V);
        vector<int> check(V);
        vector<int> safe;
        
        for(int i=0; i<V; i++)
        {
            if(visited[i]==0)
            {
                dfs(i, V, graph, visited, path_visited, check);
            }
        }
        
        for(int i=0; i<V; i++)
        {
            if(check[i]==1) 
                safe.push_back(i);
        }
        
        return safe;
    }
    
};