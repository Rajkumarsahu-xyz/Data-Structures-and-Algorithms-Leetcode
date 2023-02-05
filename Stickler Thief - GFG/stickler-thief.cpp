//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int robber(int nums[], int n, vector<int>& dp)
    {
        if(n<0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        
        int notrobb = 0 + robber(nums, n-1, dp);
        int robb = nums[n] + robber(nums, n-2, dp);
        
        return dp[n] = max(notrobb, robb);
    }
    
    
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n+1, -1);
        return robber(arr, n-1, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends