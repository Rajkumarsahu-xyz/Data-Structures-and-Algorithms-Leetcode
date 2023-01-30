//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) 
	{
	    vector<int> adj[n];
        for(auto x : prerequisites)
        {
            adj[x.first].push_back(x.second);
        }
        
        vector<int> kahn, indegree(n);
	    queue<int> q;
	    for(int i=0; i<n; i++)
	    {
	        for(auto x : adj[i])
	        {
	            indegree[x]++;
	        }
	    }
	    
	    for(int i=0; i<n; i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        kahn.push_back(node);
	        for(auto x : adj[node])
	        {
	            indegree[x]--;
	            if(indegree[x] == 0) q.push(x);
	        }
	    }
	    
	    return (kahn.size() == n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends