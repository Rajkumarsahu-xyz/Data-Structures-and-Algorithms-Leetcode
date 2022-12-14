class Solution {
public:
    
    int robber(vector<int>& nums, int n, vector<int>& dp)
    {
        if(n<0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        
        int notrobb = 0 + robber(nums, n-1, dp);
        int robb = nums[n] + robber(nums, n-2, dp);
        
        return dp[n] = max(notrobb, robb);
    }
    
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return robber(nums, n-1, dp);
    }
};