class Solution {
public:
    
    int coinchange(int amount, vector<int>& coins, int n, vector<vector<int>>& dp)
    {
        if(n == 0)
        {
            return (amount % coins[n] == 0);
        }
        
        if(dp[n][amount] != -1)
            return dp[n][amount];
    
        int take = 0;
        if(coins[n] <= amount)
            take = coinchange(amount-coins[n], coins, n, dp);
        int notTake = coinchange(amount, coins, n-1, dp);
    
        return dp[n][amount] = take+notTake;
    }
    
    
    int change(int amount, vector<int>& coins) 
    {
        if(amount == 0)
            return 1;
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return coinchange(amount, coins, n-1, dp);
    }
};