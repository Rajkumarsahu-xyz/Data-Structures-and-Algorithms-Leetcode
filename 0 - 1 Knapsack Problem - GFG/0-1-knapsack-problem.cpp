//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knap(int W, int wt[], int val[], int n, vector<vector<int>>& dp)
    {
        if(n==0)
        {
            if(wt[n] <= W)
            {
                return val[n];
            }
            
            return 0;
        }
        
        if(dp[n][W] != -1)
        {
            return dp[n][W];
        }
        
        int nottake = 0 + knap(W, wt, val, n-1, dp);
        int take = 0;
        if(wt[n] <= W)
        {
            take = val[n] + knap(W-wt[n], wt, val, n-1, dp);
        }
        
        return dp[n][W] = max(take, nottake);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        return knap(W, wt, val, n-1, dp);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends