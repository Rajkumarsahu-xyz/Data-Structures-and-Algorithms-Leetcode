class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0, mx = INT_MIN;
        
        int i=0;
        while(i<n)
        {
            sum += nums[i];
            mx = max(mx, sum);
            if(sum < 0)
                sum = 0;
            i++;
        }
        
        return mx;
    }
};