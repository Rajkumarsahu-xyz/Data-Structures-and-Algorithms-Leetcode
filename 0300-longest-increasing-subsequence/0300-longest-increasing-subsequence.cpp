class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int i = 0;
        for(auto x: nums) 
        {
            if(i==0 || nums[i-1]<x) 
                nums[i++] = x;
            else
                *lower_bound(nums.begin(), nums.begin()+i, x) = x;
        }
        
        return i;
    }
};