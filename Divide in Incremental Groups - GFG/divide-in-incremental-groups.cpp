//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countways(int k, int N, int K, int curr, vector<vector<vector<int>>> &dp)
    {
        if(curr>N)
            return 0;
        if(K==0)
            return curr==N;
            
        if(dp[k][K][curr] != -1)
            return dp[k][K][curr];
        
        int ctr = 0;
        for(int i=k; i<=N; i++)
        {
            ctr += countways(i, N, K-1, curr+i, dp);
        }
        
        return dp[k][K][curr] = ctr;
    }
    
    int countWaystoDivide(int N, int K) 
    {
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(K+1, vector<int>(N+1, -1)));
        return countways(1, N ,K, 0, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends