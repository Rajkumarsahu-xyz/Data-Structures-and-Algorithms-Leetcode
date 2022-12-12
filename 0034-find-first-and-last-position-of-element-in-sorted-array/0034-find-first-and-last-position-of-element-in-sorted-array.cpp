class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int i=0, j=nums.size()-1;
        int first=-1, last=-1;
        
        while(i <= j)
        {
            int mid = i + (j-i)/2;
            if(nums[mid] == target)
            {
                if(mid == 0  ||  nums[mid-1] != nums[mid])
                {
                    first = mid;
                    break;
                }
                else
                    j = mid-1;
            }
            
            else if(nums[mid] < target)
                i = mid+1;
            else
                j = mid-1;
        }
        
        i=0, j=nums.size()-1;
        while(i <= j)
        {
            int mid = i + (j-i)/2;
            if(nums[mid] == target)
            {
                if(mid == nums.size()-1  ||  nums[mid+1] != nums[mid])
                {
                    last = mid;
                    break;
                }
                else
                    i = mid+1;
            }
            
            else if(nums[mid] < target)
                i = mid+1;
            else
                j = mid-1;
        }
        
        
        return {first, last};
    }
};