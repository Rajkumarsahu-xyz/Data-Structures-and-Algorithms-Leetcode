class Solution {
public:
    int jump(vector<int>& nums, int i, int n, vector<int>& dp)
    {
        if(i >= n-1)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int ans = 1e9;
        for(int j=1; j<=nums[i]; j++)
        {
            ans = min(ans, 1+jump(nums, i+j, n, dp));
        }
        return dp[i] = ans;
    }
    
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return jump(nums, 0, n, dp);
    }
};