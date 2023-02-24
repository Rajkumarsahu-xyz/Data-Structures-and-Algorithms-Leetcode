//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        unordered_map<int, vector<vector<int>>> mp;
        
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w1=edges[i][2];
            int w2=edges[i][3];
            
            mp[u].push_back({v, w1, w2});
            mp[v].push_back({u, w1, w2});
        }
        
        
        vector<pair<int, int>> ans(n+1, {INT_MAX, INT_MAX});
        
        
        ans[a].first=0;
        ans[a].second=0;
        
        queue<int> que;
        
        que.push(a);
        
        while(!que.empty()){
            int top=que.front();
            que.pop();
            
            for(auto it: mp[top]){
                int v=it[0];
                int w1=it[1];
                int w2=it[2];
                
                bool flag=false;
                
                if(ans[top].first + w1 < ans[v].first){
                    ans[v].first=ans[top].first + w1;
                    flag=true;
                }
                if(ans[top].second + w2 < ans[v].first){
                    ans[v].first=ans[top].second + w2;
                    flag=true;
                }
                if(ans[top].second + w1 < ans[v].second){
                    ans[v].second=ans[top].second + w1;
                    flag=true;
                }
                
                if(flag)
                    que.push(v);
            }
        }
        
        if(ans[b].second!=INT_MAX){
            return min(ans[b].second, ans[b].first);
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends