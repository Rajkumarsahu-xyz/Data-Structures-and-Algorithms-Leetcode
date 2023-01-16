class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> ans;
        int f=0;
        if(intervals.empty())
        {
            ans.push_back({newInterval[0], newInterval[1]});
            f = -1;
        }
        for(int i=0; i<intervals.size();)
        {
            if(intervals[i][0] > newInterval[0]  &&  f==0)
            {
                ans.push_back({newInterval[0], newInterval[1]});
                f = -1;
            }
            
            else
            {
                ans.push_back({intervals[i][0], intervals[i][1]});
                i++;
            }
        }
        if(f==0)
            ans.push_back({newInterval[0], newInterval[1]});
        
        intervals = ans;
        ans.clear();
        
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