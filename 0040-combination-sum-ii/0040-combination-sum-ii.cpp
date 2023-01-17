class Solution {
public:
    void combination(vector<int>& candidates, vector<int>& combo, int i, int n, int sum, int target, vector<vector<int>>& ans)
    {
        if(sum == target)
        {
            ans.push_back(combo);
            return;
        }
        else if(sum>target)
            return;
        
        
        for(int k = i; k < n; k++)
        {
            if(k != i && candidates[k]==candidates[k-1])
                continue;
            if(sum+candidates[i] <= target)
            {
                combo.push_back(candidates[k]);
                combination(candidates, combo, k+1, n, sum+candidates[k], target, ans);
                combo.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combo;
        int i=0, sum=0;
        
        combination(candidates, combo, i, n, sum, target, ans);
        return ans;
    }
};