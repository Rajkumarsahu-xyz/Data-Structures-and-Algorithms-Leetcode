class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int i=0, j=nums.size()-1;
        
        int mid = i + (j-i)/2;
        while(i<=j)
        {
            mid = i + (j-i)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                i = mid+1;
            else
                j = mid-1;
        }
        
        if(nums[nums.size()-1] < target  ||  nums[mid]<target)
            return mid+1;
        else
            return mid;
    }
};