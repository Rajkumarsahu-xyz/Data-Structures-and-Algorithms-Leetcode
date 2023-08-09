class Solution {
public:
    
    bool isFeasible(vector<int>& nums, int p, int maxdiff, int n)
    {
        int ctr = 0;
        int i =0;
        while(i<n-1)
        {
            if(nums[i+1]-nums[i] <= maxdiff)
            {
                ctr++;
                i++;
            }
            i++;
        }
        
        return ctr >= p;
    }
    
    int minimizeMax(vector<int>& nums, int p) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int i=0, j = nums[n-1]-nums[0]; // range of possible differences between pairs
        
        int ans = 0;
        while(i <= j)
        {
            int mid = i + (j-i)/2;
            if(isFeasible(nums, p, mid, n)) 
            {
                ans = mid;
                j = mid-1;
            }
            else
            {
                i = mid+1;
            }
        }
        
        return ans;
        
    }
};