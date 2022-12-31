class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int i=0, j=nums.size()-1;
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(mid%2 == 0)
            {
                if(mid==0  &&  nums[mid]!=nums[mid+1])
                    return nums[mid];
                if(mid==n-1  &&  nums[mid-1]!=nums[mid])
                    return nums[mid];
                
                if(nums[mid] != nums[mid-1]  &&  nums[mid] != nums[mid+1])
                    return nums[mid];
                else if(nums[mid] == nums[mid-1])
                    j = mid-1;
                else
                    i = mid+1;
            }
            
            else
            {
                if(mid==0  &&  nums[mid]!=nums[mid+1])
                    return nums[mid];
                if(mid==n-1  &&  nums[mid-1]!=nums[mid])
                    return nums[mid];
                
                if(nums[mid] != nums[mid-1]  &&  nums[mid] != nums[mid+1])
                    return nums[mid];
                else if(nums[mid] != nums[mid-1])
                    j = mid-1;
                else
                    i = mid+1;
            }
        }
        
        return -1;
    }
};