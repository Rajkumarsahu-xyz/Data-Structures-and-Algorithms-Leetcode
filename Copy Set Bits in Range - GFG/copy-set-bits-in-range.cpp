//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int setSetBit(int32_t x, int32_t y, int32_t l, int32_t r){
        l -= 1;
        if(r == 32) {
            return ((((~0 >> l) << l) & y) | x); //~0 == -1
        }
        return ((((((1 << r) - 1) >> l) << l) & y) | x);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends