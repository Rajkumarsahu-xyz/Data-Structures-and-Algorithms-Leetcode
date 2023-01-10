class Solution {
public:
    void combination(vector<int>& candidates, vector<int>& combo, int i, int n, int sum, int target, vector<vector<int>>& ans)
    {
        if(i==n-1)
        {
            if((target-sum)%candidates[i] == 0)
            {
                int k = (target-sum)/candidates[i];
                int l = k;
                while(k--)
                {
                    combo.push_back(candidates[i]);
                }
                ans.push_back(combo);
                while(l--)
                {
                    combo.pop_back();
                }
            }
            else if(sum == target)
                ans.push_back(combo);
            return;
        }
        
        combination(candidates, combo, i+1, n, sum, target, ans);
        if(sum+candidates[i] <= target)
        {
            combo.push_back(candidates[i]);
            combination(candidates, combo, i, n, sum+candidates[i], target, ans);
            combo.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> combo;
        int i=0, sum=0;
        
        combination(candidates, combo, i, n, sum, target, ans);
        return ans;
    }
};