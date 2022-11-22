class Solution {
public:
    int squares(int n, vector<int>& dp)
    {
        dp[0] = 0;
        
        for(int ind=1; ind<=n; ind++)
        {
            int ctr = 1e9;
            for(int sq=1; sq*sq<=ind; sq++)
            {
                ctr = min(ctr, 1 + dp[ind - (sq*sq)]);
            }
            dp[ind] = ctr;
        }
        
        return dp[n];
    }
    
    int numSquares(int n) 
    {
        vector<int> dp(n+1, 1e9);
        return squares(n, dp);
    }
};