//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int training(int n, vector<vector<int>> &points, int prev, vector<vector<int>>& dp)
    {
        if(n == 0)
        {
            int mx = 0;
            for(int i=0; i<3; i++)
            {
                if(i != prev)
                    mx = max(mx, points[0][i]);
            }
            return mx;
        }
        
        if(dp[n][prev] != -1)
            return dp[n][prev];
        
        int mx = 0;
        int pts = 0;
        for(int i=0; i<3; i++)
        {
            if(i != prev)
            {
                pts = points[n][i] + training(n-1, points, i, dp);
                mx = max(mx, pts);
            }
        }
        return dp[n][prev] = max(mx, pts);
    }
    int maximumPoints(vector<vector<int>>& points, int n)
    {
        int total_activity = 3;
        vector<vector<int>> dp(n, vector<int> (total_activity+1, -1));
        int prev = 3;
        return training(n-1, points, prev, dp);
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends