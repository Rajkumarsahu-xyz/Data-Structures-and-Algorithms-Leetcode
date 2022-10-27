class Solution {
public:
    
    int targetSum(vector<int>& nums, int target, int sum, int n)
    {
        if(n==-1 && target==sum)
            return 1;
        
        else if(n==-1 && target!=sum)
            return 0;
        
        return targetSum(nums, target, sum-nums[n], n-1) + targetSum(nums, target, sum+nums[n], n-1);    
    }
    
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n=nums.size(), sum=0;
        return targetSum(nums, target, sum, n-1);
    }
};