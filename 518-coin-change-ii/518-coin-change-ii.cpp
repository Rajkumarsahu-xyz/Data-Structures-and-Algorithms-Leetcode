class Solution {
public:
    
    int coinchange(int amount, vector<int>& coins, int i, int ctr, vector<vector<int>>& dp)
    {
        if(amount == 0)
        {
            ctr++;
            return ctr;
        }
        
        if(amount < 0  ||  i == coins.size())
            return ctr;
        
        if(dp[i][amount] != -1)
            return dp[i][amount];
    
        int ctr1 = coinchange(amount-coins[i], coins, i, ctr, dp);
        int ctr2 = coinchange(amount, coins, i+1, ctr, dp);
    
        return dp[i][amount] = ctr1+ctr2;
    }
    
    
    int change(int amount, vector<int>& coins) 
    {
        if(amount == 0)
            return 1;
        
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        int i=0, ctr=0;
        return coinchange(amount, coins, i, ctr, dp);
    }
};