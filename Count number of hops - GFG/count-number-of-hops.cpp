//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    long long ways(int n, vector<int> &dp)
    {
        if(n == 0)
        {
            return 1;
        }
        if(n < 0)
        {
            return 0;
        }
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        long long ctr = (ways(n-1, dp) + ways(n-2, dp) + ways(n-3, dp)) % 1000000007;
        
        return dp[n] = ctr;
    }
    
    long long countWays(int n)
    {
        vector<int> dp(n+1, -1);
        return ways(n, dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends