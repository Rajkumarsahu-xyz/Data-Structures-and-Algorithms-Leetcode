class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i=0; i<n; i++) 
        {
            int m = abs(nums[i]) - 1;
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }
        
        for(int i=0; i<n; i++) 
        {
            if(nums[i] > 0) 
                nums.push_back(i+1);
        }
        
        nums.erase(nums.begin(), nums.begin()+n);
        
        return nums;
    }
};