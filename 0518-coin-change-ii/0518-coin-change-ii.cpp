class Solution {
public:
    
    int coinchange(int amount, vector<int>& coins, int i, int n, vector<vector<int>>& dp)
    {
        if(i == n-1)
        {
            if(amount%coins[n-1] == 0)
                return 1;
            return 0;
        }
        
        if(dp[i][amount] != -1)
            return dp[i][amount];
        
        int take = 0, notTake = 0;
        if(coins[i] <= amount)
            take = coinchange(amount-coins[i], coins, i, n, dp);
        notTake = coinchange(amount, coins, i+1, n, dp);
        
        return dp[i][amount] = take + notTake;
        
    }
    
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return coinchange(amount, coins, 0, n, dp);
    }
};