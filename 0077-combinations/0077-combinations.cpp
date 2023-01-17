class Solution {
public:
    void combinations(vector<int>& nums, int i, int n, vector<int>& comb, vector<vector<int>>& ans, int k)
    {
        if(comb.size() == k)
        {
            ans.push_back(comb);
            return;
        }
        
        for(int j=i; j<n; j++)
        {
            comb.push_back(nums[j]);
            combinations(nums, j+1, n, comb, ans, k);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> nums;
        for(int i=0; i<n; i++)
        {
            nums.push_back(i+1);
        }
        vector<vector<int>> ans;
        vector<int> comb;
        
        combinations(nums, 0, n, comb, ans, k);
        return ans;
    }
};