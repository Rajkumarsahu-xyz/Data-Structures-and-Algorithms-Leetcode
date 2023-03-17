//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) 
{
    long long int ans = 0;
    long long int k = 1000000000039;
    long long int ctr = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0)
            ctr++;
        else
        {
            ans += (ctr*(ctr+1)/2);
            ctr = 0;
        }
    }
    
    if(ctr > 0)
    {
        ans += (ctr*(ctr+1)/2);
    }
    
    return ans;
}

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
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends