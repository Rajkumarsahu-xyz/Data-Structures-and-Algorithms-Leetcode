//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
public:
    vector<int>primes;
    
    int dfs(int node , vector<bool>&visited,vector<vector<int>> &adj){
        if(visited[node]) return 0;
        visited[node] = true;
        int count = 1;
        for(auto neigh : adj[node]){
            if(!visited[neigh]){
                count += dfs(neigh,visited,adj);
            }
        }
        return count;
    }
    
    void precompute(){
        const int maxN = 1e6+5;
        vector<bool> is_prime(maxN , true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= maxN; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= maxN; j += i)
                    is_prime[j] = false;
            }
        }
        for(int i = 2 ; i <= maxN ; i++){
            if(is_prime[i])primes.push_back(i);
        }
    }
    
    int helpSanta(int n, int m, vector<vector<int>> &adj){
        if(m == 0) return -1;
        vector<bool>visited(n+1,0);
        int maxTrans = 1;
        for(int i = 1 ; i <= n ; i++){
            if(!visited[i]){
                maxTrans = max(maxTrans,dfs(i,visited,adj));
            }
        }
        return primes[maxTrans-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends