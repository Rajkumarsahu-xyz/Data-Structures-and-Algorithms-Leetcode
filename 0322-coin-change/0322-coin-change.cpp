class Solution {
public:
    
    int change(int amount, vector<int>& coins, int i, vector<vector<int>>& dp)
    {
        // if(amount == 0) return 1;
        
        if(i == coins.size()-1)
        {
            if(amount%coins[i] == 0)
                return amount/coins[i];
            return 1e9;
        }
        
        if(dp[i][amount] != -1)
            return dp[i][amount];
        
         int mn2=1e9;
         int mn1 = 0+change(amount, coins, i+1, dp);
        
        if(coins[i] <= amount)
            mn2 = 1+change(amount-coins[i], coins, i, dp);
        
        return dp[i][amount] = min(mn1, mn2);
    }
    
    
    int coinChange(vector<int>& coins, int amount) 
    {
        if(amount == 0)
            return 0;
        
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        int i=0, ctr=0;
        int ans = change(amount, coins, i, dp);
        if(ans == 1e9)
            return -1;
        else
            return ans;
    }
};