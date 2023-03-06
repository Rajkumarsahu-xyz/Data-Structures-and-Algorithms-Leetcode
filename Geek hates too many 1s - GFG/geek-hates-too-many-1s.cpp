//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) 
    {
        vector<int> bits(32);
        int a = n;
        int i = 0;
        while(a > 0)
        {
            if(a%2 == 0)
                bits[i] = 0;
            else
                bits[i] = 1;
                
            a /= 2;
            i++;
        }
        
        // for(int i=0; i<bits.size(); i++)
        // {
        //     cout << bits[i] << " ";
        // }
        // cout << endl;
        
        reverse(bits.begin(), bits.end());
        int ctr = 0;
        for(int i=0; i<bits.size(); i++)
        {
            if(bits[i] == 1)
                ctr++;
            else
                ctr = 0;
            if(ctr == 3)
            {
                bits[i] = 0;
                ctr = 0;
            }
        }
        
        // for(int i=0; i<bits.size(); i++)
        // {
        //     cout << bits[i] << " ";
        // }
        // cout << endl;
        
        reverse(bits.begin(), bits.end());
        int ans = 0;
        int k = 1;
        for(int i=0; i<bits.size(); i++)
        {
            if(bits[i] == 1)
                ans += k;
            k *= 2;
        }
        
        return ans;
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
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends