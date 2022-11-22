class Solution {
public:
    int squares(int n, vector<int>& dp)
    {
        if(n == 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int ctr = INT_MAX;
        for(int i=1; i*i<=n; i++) 
        {
            ctr = min(ctr, 1 + squares(n-i*i, dp));
        }
        
        return dp[n] = ctr;
    }
    
    int numSquares(int n) 
    {
        vector<int> dp(n+1, -1);
        return squares(n, dp);
    }
};