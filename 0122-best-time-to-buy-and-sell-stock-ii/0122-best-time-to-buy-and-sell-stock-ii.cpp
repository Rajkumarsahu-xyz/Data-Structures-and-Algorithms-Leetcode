class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int i = 0;
        int profit = 0, ans = 0;
        for(int j=1; j<prices.size(); j++)
        {
            if(prices[i] < prices[j])
            {
                profit = prices[j] - prices[i];
                ans += profit;
                i = j;
            }
            
            else
                i = j;
            
        }
        
        return ans;
    }
};