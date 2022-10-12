class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        for(int i=0; i<intervals.size(); i++)
        {
            if (ans.empty() || (ans[ans.size()-1][1] < intervals[i][0])) 
                ans.push_back({intervals[i][0], intervals[i][1]});
            
            else
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
        }
        
        return ans;
    }
};