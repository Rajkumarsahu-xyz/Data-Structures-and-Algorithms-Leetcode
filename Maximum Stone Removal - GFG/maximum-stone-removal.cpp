//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
    int maxRemove(vector<vector<int>>& stones, int m) 
    {
        int maxRow = 0, maxCol = 0;
        int n = stones.size();
        for(int i=0; i<n; i++)
        {
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }
        
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int, int> stoneNodes;
        
        for(int i=0; i<n; i++)
        {
            int nodeRow = stones[i][0];
            int nodeCol = stones[i][1]+maxRow+1;
            
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow]++;
            stoneNodes[nodeCol]++;
        }

        int ctr = 0;
        for (auto x : stoneNodes)
        {
            if (ds.findUPar(x.first) == x.first) 
            {
                ctr++;
            }
        }
        
        return n - ctr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends