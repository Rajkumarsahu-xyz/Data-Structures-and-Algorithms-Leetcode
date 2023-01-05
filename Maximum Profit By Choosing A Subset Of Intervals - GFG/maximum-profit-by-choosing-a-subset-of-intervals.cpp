//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }

    int maximum_profit(int n, vector<vector<int>> &intervals) 
    {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<int>ans(n);
        ans[0]=intervals[0][2];
        for(int i=1;i<n;i++)
        {
            ans[i]=intervals[i][2];
            for(int j=0;j<i;j++)
            {
                if(intervals[j][1]<=intervals[i][0])
                {
                    ans[i]=max(ans[i],ans[j]+intervals[i][2]);
                }
            }
        }
        
        return *max_element(ans.begin(),ans.end());
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends