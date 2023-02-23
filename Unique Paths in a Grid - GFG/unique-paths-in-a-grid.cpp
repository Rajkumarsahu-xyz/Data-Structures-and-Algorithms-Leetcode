//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
     int mod = 1e9+7;
    int paths(int m, int n, vector<vector<int>> &grid, vector<vector<int>>& dp)
    {
        if(m < 0  ||  n < 0 || grid[m][n] == 0)
            return 0;
        
        if(m == 0  &&  n == 0)
            return 1;
        
        if(dp[m][n] != -1)
            return dp[m][n];
            
        int right = 0, bottom = 0;
        right = paths(m-1, n, grid, dp);
        bottom = paths(m, n-1, grid, dp);
        
        return dp[m][n] = (right + bottom) % (mod);
    }
    
    int uniquePaths(int m, int n, vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return paths(m-1, n-1, grid, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends