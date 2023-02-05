//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int climb(int n, vector<int>& height, int k , vector<int>& dp)
    {
        if(n == 0)
            return 0;
        
        else if(n < 0)
            return 1e9;
        
        if(dp[n] != -1)
            return dp[n];
            
        int mn = 1e9;
        for(int i =1;i<=k;i++)
        {
            if(i>n)
            {
                break;
            }
            else
            {
                int jumpEnergy = abs(height[n]-height[n-i]) + climb(n-i, height, k, dp);
                mn = min(mn,jumpEnergy);
            }
        }
        
        return dp[n] = mn;
    }
  
    int minimizeCost(vector<int>& height, int n, int k) 
    {
        vector<int> dp(n+1, -1);
        return climb(n-1, height, k, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends