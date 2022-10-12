class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int l=-1, r = nums.size(), i=0;
        while(i < r)
        {
            if(nums[i] == 0)
            {
                swap(nums[++l] , nums[i]);
                i++;
            }
            
            else if(nums[i] == 2)
            {
                swap(nums[--r] , nums[i]);
            }
            
            else
                i++;
        }
        
        
    }
};