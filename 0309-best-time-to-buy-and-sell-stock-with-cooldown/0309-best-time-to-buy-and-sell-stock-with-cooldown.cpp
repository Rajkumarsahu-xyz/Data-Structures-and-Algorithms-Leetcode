class Solution {
public:
    
    int profit(vector<int>& prices, int i, int n, int buy, vector<vector<int>> &dp)
    {
        if(i >= n)
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        int notTake = profit(prices, i+1, n, buy, dp);
        
        int take = 0;
        if(buy == 1)
            take = -prices[i] + profit(prices, i+1, n, 0, dp);
        else
            take = prices[i] + profit(prices, i+2, n, 1, dp);
        
        return dp[i][buy] = max(notTake, take);
    }
    
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2+1, -1));
        return profit(prices, 0, n, 1, dp);
    }
};