class Solution {
public:
    
    int coinchange(int amount, vector<int>& coins,int i, vector<vector<int>>& dp)
    {
        if(amount == 0)
        {
            return 1;
        }
        
        if(amount < 0  ||  i == coins.size())
            return 0;
        
        if(dp[i][amount] != -1)
            return dp[i][amount];
    
        int ctr1 = coinchange(amount-coins[i], coins, i, dp);
        int ctr2 = coinchange(amount, coins, i+1, dp);
    
        return dp[i][amount] = ctr1+ctr2;
    }
    
    
    int change(int amount, vector<int>& coins) 
    {
        if(amount == 0)
            return 1;
        
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        int i=0, ctr=0;
        return coinchange(amount, coins, i, dp);
    }
};