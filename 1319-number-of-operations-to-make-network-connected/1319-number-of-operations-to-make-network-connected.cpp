class DisjointSet 
{
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n) 
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) 
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) 
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) 
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) 
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) 
        {
            parent[ulp_v] = ulp_u;
        }
        else 
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) 
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) 
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else 
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};



class Solution 
{
    public:
    
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        DisjointSet ds(n);
        
        int extraedges = 0;
        for(int i=0; i<connections.size(); i++)
        {
            int ulp_u = ds.findUPar(connections[i][0]);
            int ulp_v = ds.findUPar(connections[i][1]);
            if (ulp_u == ulp_v)
                extraedges++;
            else
            {
                ds.unionBySize(connections[i][0], connections[i][1]);
            }
        }
        
        int components = 0;
        for(int i=0; i<n; i++)
        {
            if(ds.parent[i] == i)
                components++;
        }
        
        int ans = components - 1;
        if (extraedges >= ans) 
            return ans;
        return -1;
    }
};