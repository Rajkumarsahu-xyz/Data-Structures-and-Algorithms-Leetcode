//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
     int minOperation(int n)  {
        int operations = 0;
        while(n) {
            if(n%2 == 0)
                n /= 2;
            else
                n -= 1;
            operations++;
        }
        return operations;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends