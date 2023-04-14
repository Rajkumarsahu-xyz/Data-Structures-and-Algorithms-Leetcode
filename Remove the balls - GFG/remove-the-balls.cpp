//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) 
    {
        stack<int> stk1, stk2;
        stk1.push(color[0]);
        stk2.push(radius[0]);
        int i=1;
        while(i<N)
        {
            if(!stk1.empty() && stk1.top()==color[i] && stk2.top()==radius[i])
            {
                stk1.pop();
                stk2.pop();
            }
            
            else
            {
                stk1.push(color[i]);
                stk2.push(radius[i]);
            }
            i++;
        }
        
        return stk1.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends