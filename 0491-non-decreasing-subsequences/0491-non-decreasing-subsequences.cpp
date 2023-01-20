class Solution {
public:
    
    void subsequences(vector<vector<int>>& ans, vector<int>& subs, vector<int>& nums, int pos) 
    {
        if(subs.size() > 1)
            ans.push_back(subs);
        unordered_set<int> hash;
        for(int i = pos; i < nums.size(); ++i)
        {
            if((subs.empty() || nums[i] >= subs.back()) && hash.find(nums[i]) == hash.end())
            {
                subs.push_back(nums[i]);
                subsequences(ans, subs, nums, i + 1);
                subs.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> subs;
        subsequences(ans, subs, nums, 0);
        return ans;
    }
};