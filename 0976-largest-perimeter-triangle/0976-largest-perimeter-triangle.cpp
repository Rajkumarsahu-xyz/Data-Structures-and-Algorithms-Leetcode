class Solution {
public:
    int largestPerimeter(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int i =nums.size()-1;
        while(i>=2)
        {
            if(nums[i-1]+nums[i-2] > nums[i])
                return nums[i-1]+nums[i-2]+nums[i];
            
            else
                i--;
        }
        return  0;
        
    }
};