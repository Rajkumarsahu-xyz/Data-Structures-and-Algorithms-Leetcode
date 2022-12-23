class Solution {
public:
    bool isFeasible(vector<int> nums, int x, int maxOperations)
    {
        int i, n = nums.size(), ctr = 0;
        for(i=0; i<n; i++)
        {
            ctr += nums[i]/x;
            if(nums[i]%x == 0)
                ctr -= 1;
        }
        return ctr <= maxOperations;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        int n = nums.size(), low, high, mid, mx = INT_MIN, ans;
        
        for(auto x : nums)
            mx = max(mx, x);
        
        low = 1;
        high = mx;
        
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(isFeasible(nums, mid, maxOperations))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};