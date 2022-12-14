class Solution {
public:
    int delEarn(vector<int>& nums, int n, vector<int>& dp)
    {
        if(n < 0)
            return 0;
        if(n == 0)
            return nums[n];
        
        if(dp[n] != -1)
            return dp[n];
        
        int sum = nums[n];
        int j = n-1;
        
        while(j>=0 && nums[n]+1==nums[j])
        {
            j--;
        }
        while(j>=0 && nums[n]==nums[j])
        {
            sum += nums[j];
            j--;
        }
        while(j>=0 && nums[n]-1==nums[j])
        {
            j--;
        }
        
        return dp[n] = max(sum+delEarn(nums, j, dp), delEarn(nums, n-1, dp));
    }
    
    int deleteAndEarn(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return delEarn(nums, n-1, dp);
    }
};