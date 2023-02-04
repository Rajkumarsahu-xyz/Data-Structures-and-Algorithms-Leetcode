//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long int
class Solution {
  public:
    long long squaresInMatrix(int m, int n) 
    {
        ll a = m*n;
        ll mn = min(m, n);
        ll b = (abs(m-n))*(mn)*(mn+1)/2;
        ll c = (mn)*(mn+1)*((2*mn)+1)/6;
        
        return b+c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m,n;
        
        cin>>m>>n;

        Solution ob;
        cout << ob.squaresInMatrix(m,n) << endl;
    }
    return 0;
}
// } Driver Code Ends