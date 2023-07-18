class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int i = 0;
        int mx = 0;
        for(int j=1; j<prices.size(); j++)
        {
            if(prices[j] < prices[i])
            {
                i = j;
            }
            
            else
            {
                mx = max(mx, prices[j]-prices[i]);
            }
        }
        
        return mx;
    }
};