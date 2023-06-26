//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long  reversedBits(long long X) 
    {
        // code here
        bitset<32> b(X);
        for (int i=0; i<16; i++)
        {
            int temp=b[i];
            b[i]=b[31-i];
            b[31-i]=temp;
        }
        return b.to_ulong();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends