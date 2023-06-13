//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	
	int solve(vector<int> &dp,int n,int m)
	{
        if(n==1)
            return 1;
        else if(n==m)
            return 2;
        else if(n<=0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int ans = solve(dp,n-1,m)%1000000007;
        if(n>=m){
            ans+= solve(dp,n-m,m)%1000000007;
        }
        return dp[n] = ans%1000000007;
    }
    
	int countWays(int n, int m)
	{
	    vector<int> dp(n+1,-1);
        return solve(dp,n,m)%1000000007;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.countWays(n, m);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends