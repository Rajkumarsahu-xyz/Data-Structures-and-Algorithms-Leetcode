class Solution {
public:
    
    int houseRob(int n, vector<int>& nums, vector<int>& dp)
    {
        if(n < 0)
            return 0;
        if(n == 0)
            return nums[n];
        
        if(dp[n] != -1)
            return dp[n];
        
        int rob = houseRob(n-2, nums, dp) + nums[n];
        int notRob = houseRob(n-1, nums, dp);
        
        return dp[n] = max(rob, notRob);
    }
    
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return houseRob(n-1, nums, dp);
    }
};