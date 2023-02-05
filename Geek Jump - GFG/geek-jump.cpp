//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int climb(int n, vector<int>& height, vector<int>& dp)
    {
        if(n == 0)
            return 0;
        
        else if(n < 0)
            return 1e9;
        
        if(dp[n] != -1)
            return dp[n];
            
        int a = abs(height[n]- height[n-1]) + climb(n-1, height, dp);
        int b = abs(height[n]- height[n-2]) + climb(n-2, height, dp);
        
        return dp[n] = min(a, b);
    }
  
    int minimumEnergy(vector<int>& height, int n) 
    {
        vector<int> dp(n+1, -1);
        return climb(n-1, height, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends