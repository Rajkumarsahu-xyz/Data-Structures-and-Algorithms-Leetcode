class Solution {
public:
    void combinations(vector<int>& nums, int sum, int i, int k, vector<int>& comb, vector<vector<int>>& ans, int target)
    {
        if(comb.size() == k)
        {
            if(sum == target)
                ans.push_back(comb);
            return;
        }
        
        for(int j=i; j<9; j++)
        {
            if(sum+nums[j] <= target)
            {
                comb.push_back(nums[j]);
                combinations(nums, sum+nums[j], j+1, k, comb, ans, target);
                comb.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> ans;
        vector<int> comb;
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        
        combinations(nums, 0, 0, k, comb, ans, n);
        return ans;
    }
};