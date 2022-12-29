class Solution {
public:
    
    bool isfeasible(vector<int>& nums, int threshold, int divisor, int n)
    {
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i] / divisor;
            if(nums[i]%divisor != 0)
                sum++;
            
            if(sum > threshold)
                return false;
        }
        
        return true;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int min_div;
        int mx = INT_MIN;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            mx = max(mx, nums[i]);
        }
        
        if(n == threshold)
            return mx;
        
        int i=1, j=mx;
        while(i <= j)
        {
            int mid = (i+j)/2;
            if(isfeasible(nums, threshold, mid, n))
            {
                min_div = mid;
                j = mid-1;
            }
            
            else
            i = mid+1;
        }
        
        return min_div;
    }
};