class Solution {
public:
    
    int change(vector<int>& coins, int n, int amount, vector<vector<int>>& dp)
    {
        for(int x=0; x<=amount; x++)
        {
            if(x % coins[0] == 0)
                dp[0][x] = x/coins[0];
            else
                dp[0][x] = 1e9;
        }
        
        for(int ind=1; ind<n; ind++)
        {
            for(int target=0; target<=amount; target++)
            {
                int notTake = dp[ind-1][target];
                int take = 1e9;
                if(coins[ind] <= target)
                    take = 1 + dp[ind][target-coins[ind]];
                
                dp[ind][target] = min(notTake, take);
            }
        }
        
        return dp[n-1][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));
        int ans = change(coins, n, amount, dp);
        
        if(ans >= 1e9)
            return -1;
        else
            return ans;
    }
};