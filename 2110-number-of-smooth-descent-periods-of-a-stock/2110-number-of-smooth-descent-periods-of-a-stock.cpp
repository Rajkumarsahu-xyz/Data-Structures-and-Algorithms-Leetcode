class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) 
    {
        long long ans = prices.size(), ctr = 0;
        for(int i=0; i<prices.size()-1; i++)
        {
            if(prices[i]-prices[i+1] == 1)
            {
                ctr++;
                ans += ctr;
            }
            else
            {
                ctr = 0;
            }
        }

        return ans;
    }
};