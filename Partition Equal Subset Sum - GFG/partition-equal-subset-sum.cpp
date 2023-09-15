//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool equal(int i, int arr[], int s, int targetsum, vector<vector<int>> &dp)
    {
        if(i<0)
        {
            return (s==targetsum);
        }
        
        if(s > targetsum)
            return false;
        
        if(s == targetsum)
            return true;
        
        if(dp[i][s] != -1)
        {
            return dp[i][s];
        }
        
        bool k = equal(i-1, arr, s, targetsum, dp) || equal(i-1, arr, s+arr[i], targetsum, dp);
        
        return dp[i][s] = k;
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N; i++)
        {
            sum += arr[i];
        }
        
        if(sum%2 == 1)
            return false;
        
        sum /= 2;
        vector<vector<int>> dp(N+1, vector<int>(sum+1, -1));
        return equal(N-1, arr, 0, sum, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends