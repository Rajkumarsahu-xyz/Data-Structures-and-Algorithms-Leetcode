//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    vector<vector<long long> > dp;
    
    long long rec(int i, int n, int r[], int g[], int b[], int prev) {
        if(i == n)
            return 0;
        
        if(dp[prev][i] != -1)
            return dp[prev][i];
        
        long long takeRed = 1e18, takeGreen = 1e18, takeBlue = 1e18;
        
        if(prev == 0) {
            takeRed = r[i] + rec(i + 1, n, r, g, b, 1);
            takeGreen = g[i] + rec(i + 1, n, r, g, b, 2);
            takeBlue = b[i] + rec(i + 1, n, r, g, b, 3);
        }
        
        if(prev == 1) {
            takeGreen = g[i] + rec(i + 1, n, r, g, b, 2);
            takeBlue = b[i] + rec(i + 1, n, r, g, b, 3);
        }
        
        if(prev == 2) {
            takeRed = r[i] + rec(i + 1, n, r, g, b, 1);
            takeBlue = b[i] + rec(i + 1, n, r, g, b, 3);
        }
        
        if(prev == 3) {
            takeRed = r[i] + rec(i + 1, n, r, g, b, 1);
            takeGreen = g[i] + rec(i + 1, n, r, g, b, 2);
        }
        
        return dp[prev][i] = min(
            takeRed,
            min(
                takeGreen,
                takeBlue
            )
        );
    }
    
public:
    long long int distinctColoring(int n, int r[], int g[], int b[]) {
        dp = vector<vector<long long> > (4, vector<long long>(n, -1));
        
        return rec(0, n, r, g, b, 0);
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
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends