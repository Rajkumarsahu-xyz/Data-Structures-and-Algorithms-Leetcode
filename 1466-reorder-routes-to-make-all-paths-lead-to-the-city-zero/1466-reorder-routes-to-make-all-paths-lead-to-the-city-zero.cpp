// class Solution {
// public:
//     void dfs(vector<int> dirlist[], int parent, int start, int ctr)
//     {
//         for (x : dirlist[node]) 
//         {
//             int child = x.first;
//             int no
//             if (child != parent) 
//             {
//                 count += sign;
//                 dfs(child, node, adj);
//             }
//         }
//     }
    
//     int minReorder(int n, vector<vector<int>>& connections) 
//     {
//         vector<int> dirlist[n], undirlist[n];
//         for(int i=0; i<n; i++)
//         {
//             dirlist[connections[i][0]].push_back(connections[i][1]);
//             undirlist[connections[i][0]].push_back(connections[i][1]);
//             undirlist[connections[i][1]].push_back(connections[i][0]);
//         }
        
//         vector<int> visited(n);
//         visited[0] = 1;
//         int ctr = 0;
//         dfs(undirlist, -1, 0, ctr);
        
//         return ctr;
//     }
// };



class Solution {
public:
    int count = 0;
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj) {
        for (auto& [child, sign] : adj[node]) {
            if (child != parent) {
                count += sign;
                dfs(child, node, adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        dfs(0, -1, adj);
        return count;
    }
};