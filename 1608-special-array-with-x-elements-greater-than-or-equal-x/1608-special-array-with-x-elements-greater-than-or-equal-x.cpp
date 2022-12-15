class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int i=0, j=nums.size()-1;
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            auto x = lower_bound(nums.begin(), nums.end(), mid+1);
            
            if(nums.end()-x == mid+1)
                return mid+1;
            else if(nums.end()-x > mid+1)
                i = mid+1;
            else
                j = mid-1;
        }
        
        return -1;
    }
};