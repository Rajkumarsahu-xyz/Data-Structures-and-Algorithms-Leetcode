class Solution {
public:
    int parent[26];
    int rank[26];
    void makeSet()
    {
        for(int i=0; i<26; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findPar(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    
    void Union(int u, int v)
    {
        u = findPar(u);
        v = findPar(v);
        
        if(rank[u] < rank[v])
            parent[u] = v;
        else if(rank[v] < rank[u])
            parent[v] = u;
        else
            parent[v] = u, rank[u]++;
    }
    
    bool equationsPossible(vector<string>& equations) 
    {
        makeSet();
        int n = equations.size();
        
        for(int i=0; i<n; i++)
        {
            if(equations[i][1] == '=')
                Union(equations[i][0]-'a', equations[i][3]-'a');
        }
        
        for(int i=0; i<n; i++)
        {
            if(equations[i][1] == '=')
            {
                if(findPar(equations[i][0]-'a') != findPar(equations[i][3]-'a'))
                    return false;
            }
            
            else if(equations[i][1] == '!')
            {
                if(findPar(equations[i][0]-'a') == findPar(equations[i][3]-'a'))
                    return false;
            }
        }
        
        return true;
    }
};