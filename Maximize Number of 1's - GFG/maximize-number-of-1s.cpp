//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) 
    {
        int mx=0, zeroCount=0;
        int i=0, j=0;

        while(j<n)
        {
              if(arr[j]==0)
              {
                  zeroCount++;
              }

              while(zeroCount>m && i<n)
              {
                    if(arr[i]==0)
                    {
                        zeroCount--;
                    }
                    i++;
              }

            mx = max(mx,j-i+1);
            j++;
        }

        return mx;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends