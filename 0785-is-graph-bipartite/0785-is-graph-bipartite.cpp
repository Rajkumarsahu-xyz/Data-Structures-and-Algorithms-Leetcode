class Solution {
public:
//     bool dfs(int node, int color, vector<int>& colored, vector<vector<int>>& graph)
//     {
//         colored[node] = color;
        
//         for(auto x : graph[node])
//         {
//             if(colored[x] == -1)
//             {
//                 if(!dfs(x, !color, colored, graph))
//                     return false;
//             }
            
//             else if(colored[x] == color)
//                 return false;
//         }
        
//         return true;
//     }
    
    bool bfs(int start, int n, vector<vector<int>>& graph, vector<int>& colored)
    {
        queue<int> q;
        q.push(start);
        colored[start] = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto x : graph[node])
            {
                if(colored[x] == -1)
                {
                    colored[x] = !colored[node];
                    q.push(x);
                }
                else if(colored[x] == colored[node])
                    return false;
            }
        }
        
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> colored(n, -1);
        
        for(int i=0; i<n; i++)
        {
            if(colored[i] == -1)
            {
                if(!bfs(i, n, graph, colored))
                    return false;
            }
        }
        
        return true;
        
        //colored[0] = 0;
//         for(int i=0; i<n; i++)
//         {
//             if(colored[i] == -1)
//             {
//                 if(!dfs(i, 0, colored, graph))
//                     return false;
//             }
//         }
        
//         return true;
    }
};