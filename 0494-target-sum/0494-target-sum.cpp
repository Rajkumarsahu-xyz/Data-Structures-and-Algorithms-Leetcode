class Solution {
public:
    int targetsum(vector<int>& nums, int n, int target, vector<vector<int>>& dp)
    {
        
        for(int i=0; i<n; i++)
            dp[i][0] = 1;
        if(nums[0] <= target)
            dp[0][nums[0]] = 1;
        if(nums[0] == 0)
            dp[0][0] = 2;
        
        for(int ind=1; ind<n; ind++)
        {
            for(int tar=0; tar<=target; tar++)
            {
                int notTake = dp[ind-1][tar];
                int take = 0;
                if(nums[ind] <= tar)
                    take += dp[ind-1][tar-nums[ind]];
            
                dp[ind][tar] = (notTake + take)%(1000000007);
            }
        }
    
        return dp[n-1][target];
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n=nums.size(), sum=0;
        
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
        }
        
        if(sum-target < 0) 
            return 0;
        if((sum-target)%2 == 1) 
            return 0;
        
        int s = (sum - target)/2;
        vector<vector<int>> dp(n+1, vector<int> (s+1, 0));
        return targetsum(nums, n, s, dp);
    }
};