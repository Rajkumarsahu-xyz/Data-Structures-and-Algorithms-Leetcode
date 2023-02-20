//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int N){
        int old_dp[4] = {0}, mod = 1e9 + 7;
        old_dp[0] = 1;
        for(int i = 0; i < N; i++) {
            int new_dp[4] = {0};
            for(int j = 0; j < 4; j++) {
                for(int k = 1; k <= 3; k++) {
                    new_dp[j] = (new_dp[j] + old_dp[abs(j - k)]) % mod;
                }
            }
            swap(old_dp, new_dp);
        }
        return old_dp[0];
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
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends