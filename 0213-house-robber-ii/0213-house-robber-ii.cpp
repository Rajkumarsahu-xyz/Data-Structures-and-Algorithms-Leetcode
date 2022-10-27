class Solution {
public:
    long long int houseRob(int n, vector<int>& nums, vector<long long int>& dp)
    {
        if(n < 0)
            return 0;
        if(n == 0)
            return nums[n];
        
        if(dp[n] != -1)
            return dp[n];
        
        long long int rob = houseRob(n-2, nums, dp) + nums[n];
        long long int notRob = houseRob(n-1, nums, dp);
        
        return dp[n] = max(rob, notRob);
    }
    
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        int n = nums.size();
        vector<int> temp1, temp2;
        
        for(int i=0; i<nums.size()-1; i++) temp1.push_back(nums[i]);
        for(int i=1; i<nums.size(); i++) temp2.push_back(nums[i]);
        
         vector<long long int> dp(n+1, -1);
         vector<long long int> sp(n+1, -1);
            
        return max(houseRob(n-2, temp1, dp), houseRob(n-2, temp2, sp));
    }
};