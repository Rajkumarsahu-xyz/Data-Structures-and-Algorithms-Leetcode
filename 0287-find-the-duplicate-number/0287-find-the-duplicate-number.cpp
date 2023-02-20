class Solution {
public:
    bool check(vector<int>& nums, int mid)
    {
        int ctr = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] <= mid)
                ctr++;
            if(ctr > mid)
                return true;
        }
        
        return false;
    }
    
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        int i=1, j=n;
        int ans = 0;
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            if(check(nums, mid))
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