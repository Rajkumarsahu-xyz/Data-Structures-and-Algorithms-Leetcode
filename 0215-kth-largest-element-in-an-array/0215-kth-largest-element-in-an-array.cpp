class Solution {
public:
    int isfeasible(vector<int>& nums, int k, int mid)
    {
        int ctr = 0;
        for(auto x : nums)
        {
            if(x >= mid)
                ctr++;
        }
        
        return ctr;
    }
    
    int findKthLargest(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int mn = INT_MAX, mx = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        
        int i=mn, j=mx;
        int ans = 0;
        
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            int ctr = isfeasible(nums, k, mid);
            if(ctr >= k)
            {
                ans = mid;
                i = mid+1;
            }
            
            else
            {
                j = mid-1;
            }
        }
        
        return ans;
    }
};