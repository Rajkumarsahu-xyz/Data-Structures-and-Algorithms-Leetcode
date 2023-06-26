//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
  long long gcd(long long a,long long b)
  {
      if(a==0)
      {
          return b;
      }
      return gcd(b%a,a);
  }
  
  
  long long lcm(long long a,long long b,long long gcd)
  {
      return(a*b)/gcd;
  }
  
    vector<long long> lcmAndGcd(long long A, long long B) {
        long long GCD = gcd(A, B);
        long long LCM = lcm(A, B, GCD);

        return {LCM, GCD};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends