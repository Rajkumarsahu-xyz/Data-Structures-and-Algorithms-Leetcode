class Solution {
public:
    
    bool partition(vector<int>& nums, int n, int s, vector<vector<int>>& dp)
    {
        if(s==0  ||  (n==0 && s==nums[0]))
            return true;
        
        if((n==0  &&  s>0) || s<0)
            return false;
        
        if(dp[n][s] != -1)
            return dp[n][s];
        
        return dp[n][s] = partition(nums, n-1, s-nums[n], dp)  ||  partition(nums, n-1, s, dp);
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
            vector<vector<int>> dp(n+1, vector<int> ((s/2)+1, -1)); 
            return partition(nums, n-1, s/2, dp);
        }
    }
};