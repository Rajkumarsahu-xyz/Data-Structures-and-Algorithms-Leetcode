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


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        unordered_map<string, int> mp;
        int n = accounts.size();
        DisjointSet ds(n);
        
        for(int i=0; i<accounts.size(); i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                if(mp.find(accounts[i][j]) == mp.end())
                    mp[accounts[i][j]] = i;
                else
                    ds.unionBySize(i, mp[accounts[i][j]]);
            }
        }
        
        vector<vector<string>> ans;
        vector<string> merged_accounts[n];
        for(auto x : mp) 
        {
            string acc = x.first;
            int node = ds.findUPar(x.second);
            merged_accounts[node].push_back(acc);
        }
        
        
        for(int i=0; i<n; i++)
        {
            if(merged_accounts[i].size() == 0) 
                continue;
            sort(merged_accounts[i].begin(), merged_accounts[i].end());
            
            vector<string> t;
            t.push_back(accounts[i][0]);
            for(auto x : merged_accounts[i]) 
            {
                t.push_back(x);
            }
            ans.push_back(t);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};