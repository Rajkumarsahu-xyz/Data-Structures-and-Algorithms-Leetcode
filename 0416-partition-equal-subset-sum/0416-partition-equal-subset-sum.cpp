class Solution {
public:
    
    bool partition(vector<int>& nums, int n, int s, vector<vector<bool>>& dp)
    {
        for(int i=0; i<n; i++)
        dp[i][0] = true;
    
        if(nums[0]<=s)
            dp[0][nums[0]] = true;
    
        for(int ind = 1; ind<n; ind++)
        {
            for(int target= 1; target<=s; target++)
            { 
                bool notTaken = dp[ind-1][target];

                bool taken = false;
                if(nums[ind]<=target)
                    taken = dp[ind-1][target-nums[ind]];
        
                dp[ind][target] = notTaken || taken;
            }
        }
    
        return dp[n-1][s];
    }
    
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int s = 0;
        for(int i=0; i<n; i++)
        {
            s += nums[i];
        }
        
        if(s%2 != 0)
            return false;
        
        else
        {
            vector<vector<bool>> dp(n+1, vector<bool> ((s/2)+1, false)); 
            return partition(nums, n, s/2, dp);
        }
    }
};