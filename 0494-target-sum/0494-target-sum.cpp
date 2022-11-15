class Solution {
public:
    int targetsum(vector<int>& nums, int n, int target, vector<vector<int>>& dp)
    {
        if(n == 0)
        {
            if(target==0  &&  nums[0]==0)
                return 2;
            else if(target==0  || nums[0]==target)
                return 1;
            else
                return 0;
        }
        
        if(dp[n][target] != -1)
            return dp[n][target];
        
        int notTake = 0 + targetsum(nums, n-1, target, dp);
        int take = 0;
        if(nums[n] <= target)
            take = targetsum(nums, n-1, target-nums[n], dp);
        
        return dp[n][target] = notTake + take;
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
        vector<vector<int>> dp(n+1, vector<int> (s+1, -1));
        return targetsum(nums, n-1, s, dp);
    }
};