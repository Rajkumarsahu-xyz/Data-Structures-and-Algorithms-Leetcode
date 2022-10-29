class Solution {
public:
    
    int XORsum(vector<int>& nums, int i, int n, int xr)
    {
        if(i==n)
            return xr;
        
        return XORsum(nums, i+1, n, xr^nums[i]) + XORsum(nums, i+1, n, xr);
    }
    
    int subsetXORSum(vector<int>& nums) 
    {
        int n = nums.size(), xr=0; 
        return XORsum(nums, 0, n, xr);
    }
};