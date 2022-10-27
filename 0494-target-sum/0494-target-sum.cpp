class Solution {
public:
    
    int targetSum(vector<int>& nums, int target, int sum, int n, vector<vector<int>>& dp)
    {
        if(n==-1 && target==sum)
            return 1;
        
        else if(n==-1 && target!=sum)
            return 0;
        
        if(dp[n][sum+1000] != -1)
            return dp[n][sum+1000];
        
        int plus = targetSum(nums, target, sum+nums[n], n-1, dp);
        int minus = targetSum(nums, target, sum-nums[n], n-1, dp);
        
        return dp[n][sum+1000] = plus + minus;
    }
    
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n=nums.size(), sum=0;
        vector<vector<int>> dp(20+1, vector<int>((2000)+1, -1));
        return targetSum(nums, target, sum, n-1, dp);
    }
};