class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<long long> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=amount;i++)
        {
            if(dp[i]==INT_MAX)
            {
                continue;
            }
            for(int j=0;j<coins.size();j++)
            {
                long long new_amount=(long long)i+(long long)coins[j];
                if(new_amount<=amount)
                {
                    dp[new_amount]=min(dp[new_amount],dp[i]+1);
                }
            }
        }
        if(dp[amount]==INT_MAX)
        {
            return -1;
        }
        return dp[amount];
    }
};