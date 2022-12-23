class Solution {
public:
    int profit(vector<int>&prices, int i, int n, int buy, int fee, vector<vector<int>>& dp)
    {
        if(i == n)
            return 0;
       
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        int notTake = profit(prices, i+1, n, buy, fee, dp);
        
        int take = 0;
        if(buy)
            take = -prices[i] + profit(prices, i+1 , n, 0, fee, dp);
        else
            take = (prices[i]-fee) + profit(prices, i+1 , n, 1, fee, dp);
            
        return dp[i][buy] = max(notTake, take);
    }
    
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size(), buy = 1;
        vector<vector<int>> dp(n+1, vector<int>(2+1, -1));
        
        return profit(prices, 0, n, 1, fee, dp);
    }
};