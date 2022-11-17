//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
  
    bool isPrime(int n)
    {
        if(n == 1) 
        return false;
    
        for(int i=2; i*i<=n; i++)
        {
            if(n%i == 0)
            return false;
        }
    
        return true;
    }
  
    int nthTerm(int n)
    {
        int x=2, i=1;
        while(i <= n)
        {
            if(isPrime(x))
            {
                i++;
            }
            x++;
        }
        
        return (x)*n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n;
        Solution ob;
        cout<<ob.nthTerm(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends