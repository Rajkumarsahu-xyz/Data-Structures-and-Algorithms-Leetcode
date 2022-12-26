class Solution {
public:
    bool jump(vector<int>& nums, int i, int n, vector<int>& dp)
    {
        if(i == n-1)
            return true;
        else if(i>=n || nums[i]==0)
            return false;
        if(dp[i] != -1)
            return dp[i];
        
        bool ans = false;
        for(int j=1; j<=nums[i]; j++)
        {
            ans = jump(nums, i+j, n, dp);
            if(ans == true)
                break;
        }
        return dp[i] = ans;
    }
    
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return jump(nums, 0, n, dp);
    }
};