class Solution {
    public :
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int Xor = 0, xor0 = 0, xor1 = 0;
        for (int n: nums)
            Xor ^= n;
        for (int i = 1; i <= nums.size(); i++)
            Xor ^= i;
        
        int p = Xor & ~(Xor - 1);
        
        for (int n: nums) 
        {
            if ((n & p) != 0)
                xor1 ^= n;
            else
                xor0 ^= n;
        }
        
        for (int i = 1; i <= nums.size(); i++) 
        {
            if ((i & p) != 0)
                xor1 ^= i;
            else
                xor0 ^= i;
        }
        
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] == xor0)
                return {xor0, xor1};
        }
        
        return {xor1, xor0};
    }
};