//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    vector<int> visited;
    int ans=0;
    bool solve(int node, vector<vector<int>> &adj){
        bool select = false;        //need to select curr node or not
        visited[node] = true;
        for(auto nbr : adj[node])
        {
            if(!visited[nbr]){      
                bool isChildSelected = solve(nbr, adj);     //check kya kisi child par light algaya he 
                
                if(isChildSelected == false)//agar child par light nhi lagaya he to curr node par lagana hi padega 
                    select = true;      
            }
        }
        if(select)  
            ans++;
            
        return select;
    }
  public:
    int countVertex(int n, vector<vector<int>>edges){
        vector<vector<int>> adj(n+1);
        for(auto p : edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        visited.resize(n+1,0);
        solve(1, adj);
        if(ans == 0)
            ans++;
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends