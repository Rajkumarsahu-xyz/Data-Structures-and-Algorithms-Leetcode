class Solution {
public:
    void dfs(int node, vector<int> adjlist[], long long &ctr, vector<int> &visited)
    {
        ctr++;
        visited[node] = 1;
        
        for(auto x : adjlist[node])
        {
            if(visited[x] == 0)
            {
                dfs(x, adjlist, ctr, visited);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        vector<int> adjlist[n];
        for(int i=0; i<edges.size(); i++)
        {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> visited(n);
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                long long ctr = 0;
                dfs(i, adjlist, ctr, visited);
                ans.push_back(ctr);
            }
        }
        
        // for(int i=0; i<ans.size(); i++)
        // {
        //     cout << ans[i] << " ";
        // }
        // cout << endl;
        
        long long a = 0;
        long long res = 0;
        for(int i=0; i<ans.size(); i++)
        {
            a += ans[i];
            res += (ans[i] * (n-a));
        }
        
        return res;
        
    }
};