//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
     vector<int> duplicates(int arr[], int n) 
     {
        unordered_map<int,int> mp;
        vector<int> result;
        for(int i=0;i<n;i++)
        mp[arr[i]]++;
        
        for(auto it : mp)
        if(it.second>=2)
        result.push_back(it.first);
        sort(result.begin(),result.end());
        if(result.size())
        return result;
        return {-1};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends