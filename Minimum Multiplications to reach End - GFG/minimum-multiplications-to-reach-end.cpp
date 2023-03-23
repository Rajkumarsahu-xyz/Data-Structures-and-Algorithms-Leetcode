//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) 
    {
        queue<pair<int, int>> q;
        q.push({0, start});
        vector<int> distance(100000, 1e9);
        distance[start] = 0;
        
        while(!q.empty())
        {
            int node = q.front().second;
            int steps = q.front().first;
            q.pop();
            
            for(auto x : arr)
            {
                int product = (x*node)%(100000);
                if(product == end)
                    return steps+1;
                if(steps+1 < distance[product])
                {
                    distance[product] = steps+1;
                    q.push({steps+1, product});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends