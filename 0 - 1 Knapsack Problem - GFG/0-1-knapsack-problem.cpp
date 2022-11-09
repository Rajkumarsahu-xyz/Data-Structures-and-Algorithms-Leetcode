//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int sack(int weight[], int value[], int n, int maxWeight, vector<vector<int>>& dp)
    {
        if(n == 0)
        {
            if(weight[n] <= maxWeight)
                return value[n];
            return 0;
        }
    
        if(dp[n][maxWeight] != -1)
            return dp[n][maxWeight];
    
        int notSteal = sack(weight, value, n-1, maxWeight, dp);
        int Steal = 0;
        if(weight[n] <= maxWeight)
        {
            Steal = value[n] + sack(weight, value, n-1, maxWeight-weight[n], dp);
        }
    
        return dp[n][maxWeight] = max(notSteal, Steal);
    }

    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n+1, vector<int> (W+1, -1));
        return sack(wt, val, n-1, W, dp);
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