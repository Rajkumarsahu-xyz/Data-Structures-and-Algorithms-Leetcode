class Solution {
public:
    
    int coinchange(int amount, vector<int>& coins, int n, vector<vector<int>>& dp)
    {
        for(int x=0; x<=amount; x++)
        {
            if(x%coins[0] == 0)
                dp[0][x] = 1;
        }
        
        for(int ind=1; ind<n; ind++)
        {
            for(int target=0; target<=amount; target++)
            {
                int notTake = dp[ind-1][target];
                int take = 0;
                if(coins[ind] <= target)
                    take = dp[ind][target-coins[ind]];
                
                dp[ind][target] = take + notTake;
            }
        }
        
        return dp[n-1][amount];
    }
    
    
    int change(int amount, vector<int>& coins) 
    {
        if(amount == 0)
            return 1;
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        return coinchange(amount, coins, n, dp);
    }
};