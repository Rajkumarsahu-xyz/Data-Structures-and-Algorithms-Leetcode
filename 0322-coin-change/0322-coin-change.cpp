class Solution {
public:
    
    int change(vector<int>& coins, int n, int amount, vector<vector<int>>& dp)
    {
        if(n == 0)
        {
            if(amount % coins[n] == 0)
                return amount/coins[n];
            else
                return 1e9;
        }
        
        if(dp[n][amount] != -1)
            return dp[n][amount];
        
        int notTake = change(coins, n-1, amount, dp);
        int take = 1e9;
        if(coins[n] <= amount)
            take = 1 + change(coins, n, amount-coins[n], dp);
        
        return dp[n][amount] = min(notTake, take);
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        int ans = change(coins, n-1, amount, dp);
        
        if(ans >= 1e9)
            return -1;
        else
            return ans;
    }
};