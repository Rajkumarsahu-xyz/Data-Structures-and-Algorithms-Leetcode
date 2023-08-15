class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        int n = nums.size();
        vector<int> left, right;
        int ctr = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] < pivot)
                left.push_back(nums[i]);
            else if(nums[i] > pivot)
                right.push_back(nums[i]);
            else
                ctr++;
        }
        
        vector<int> ans;
        int i=0;
        while(i<left.size())
        {
            ans.push_back(left[i]);
            i++;
        }
        
        while(ctr--)
        {
            ans.push_back(pivot);
        }
        
        i=0;
        while(i<right.size())
        {
            ans.push_back(right[i]);
            i++;
        }
        
        return ans;
    }
};