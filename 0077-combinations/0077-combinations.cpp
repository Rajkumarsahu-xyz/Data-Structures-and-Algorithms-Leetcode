class Solution {
public:
    
    void combo(vector<int> &nums, int i, int n, vector<int> &v, vector<vector<int>> &ans, int k)
    {
        if(v.size() == k)
        {
            ans.push_back(v);
            return;
        }
        
        if(i == n)
            return;
        
        combo(nums, i+1, n, v, ans, k);
        v.push_back(nums[i]);
        combo(nums, i+1, n, v, ans, k);
        v.pop_back();
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> nums;
        for(int i=1; i<=n; i++)
        {
            nums.push_back(i);
        }
        
        vector<vector<int>> ans;
        vector<int> v;
        combo(nums, 0, n, v, ans, k);
        
        return ans;
    }
};
