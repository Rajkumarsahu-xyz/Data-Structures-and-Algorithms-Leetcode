class Solution {
public:
    void permutations(vector<int>& nums, int i, int n, vector<vector<int>>& ans)
    {
        if(i == n-1)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int j=i; j<n; j++)
        {
            swap(nums[i], nums[j]);
            permutations(nums, i+1, n, ans);
            swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> ans;
        permutations(nums, 0, n, ans);
        return ans;
    }
};