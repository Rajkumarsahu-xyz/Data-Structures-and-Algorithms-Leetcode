//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int cost(vector<vector<int>> &colors, int N, int prev,  vector<vector<int>>& dp)
    {
        if(N == 0)
        {
            int mn = INT_MAX;
            for(int i=0; i<3; i++)
            {
                if(i != prev)
                    mn = min(mn, colors[0][i]);
            }
            return mn;
        }
        
        if(dp[N][prev] != -1)
        {
            return dp[N][prev];
        }
        
        int mn = INT_MAX;
        int ct = 0;
        for(int i=0; i<3; i++)
        {
            if(i!=prev)
            {
                ct = colors[N][i] + cost(colors, N-1, i, dp);
                mn = min(mn, ct);
            }
        }
        
        return dp[N][prev] = min(mn, ct);
        
    }

    int minCost(vector<vector<int>> &colors, int N) 
    {
        int prev = 3;
        int sum = 0;
        vector<vector<int>> dp(N+1, vector<int>(3+1, -1));
        return cost(colors, N-1, prev, dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends