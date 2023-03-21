class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int ctr = 0, mx = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                ctr++;
            }
            
            else
            {
                mx = max(mx, ctr);
                ctr = 0;
            }
        }
        
        if(ctr > 0)
            mx = max(mx, ctr);
        
        return mx;
    }
};