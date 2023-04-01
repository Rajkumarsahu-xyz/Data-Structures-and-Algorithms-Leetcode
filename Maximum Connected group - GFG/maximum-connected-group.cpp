//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
    int MaxConnection(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(grid[row][col] == 1) 
                {
                    vector<int> delmat = {-1, 0, 1, 0, -1};
                    for(int i=0; i<4; i++)
                    {
                        int nrow = row + delmat[i];
                        int ncol = col + delmat[i+1];
                        if (nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 1)
                        {
                            int nodeNo = row*n + col;
                            int newNodeNo = nrow*n + ncol;
                            ds.unionBySize(nodeNo, newNodeNo);
                        }
                    }
                }
            }
        }
        
        
        int mx = 0;
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(grid[row][col] == 0)
                {
                    vector<int> delmat = {-1, 0, 1, 0, -1};
                    set<int> component_parents;
                    for(int i=0; i<4; i++)
                    {
                        int nrow = row + delmat[i];
                        int ncol = col + delmat[i+1];
                        if (nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 1)
                        {
                            int newNodeNo = nrow*n + ncol;
                            component_parents.insert(ds.findUPar(newNodeNo));
                        }
                    }

                    int sizeTotal = 0;
                    for(auto x : component_parents)
                    {
                        sizeTotal += ds.size[x];
                    }
                    mx = max(mx, sizeTotal+1);
                }
            }
        }
        
        for(int cellNo=0; cellNo<n*n; cellNo++)
        {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        
        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends