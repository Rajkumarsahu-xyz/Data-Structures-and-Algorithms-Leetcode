class Solution {
public:
    void paths(vector<vector<int>>& graph, int start, int n, vector<int> v, vector<vector<int>>& ans)
    {
        v.push_back(start);
        if(start == n)
            ans.push_back(v);
        
        for(auto x : graph[start])
        {
            paths(graph, x, n, v, ans);
        }
        v.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size(); 
        int start = 0;
        vector<vector<int>> ans;
        vector<int> v;
        paths(graph, start, n-1, v, ans);
        
        return ans;
    }
};