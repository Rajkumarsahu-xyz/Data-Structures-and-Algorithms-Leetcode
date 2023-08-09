class Solution {
public:
    int minDifference(vector<int>& nums) 
    {
        int n = nums.size();
        if(n <= 4) 
            return 0;
        
        partial_sort(nums.begin(), nums.begin() + 4, nums.end());
        partial_sort(nums.rbegin(), nums.rbegin() + 4, nums.rend(), greater<int>());
        
        int ans = INT_MAX;
        for (int l=0; l<=3; ++l)
            ans = min(ans, nums[n-4+l]-nums[l]);
        
        return ans;
    }
};