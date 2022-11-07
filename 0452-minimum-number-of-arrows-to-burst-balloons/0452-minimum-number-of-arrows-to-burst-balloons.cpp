class Solution {
public:
    
    static bool cmp(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second < b.second;
    }
    
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        vector<pair<int, int>> act;
        for(int i=0; i<points.size(); i++)
        {
            act.push_back({points[i][0], points[i][1]});
        }
        
        sort(act.begin(), act.end(), cmp);
        
        int ctr = 1, prev = act[0].second;
        for(int i=1; i<points.size(); i++)
        {
            if(prev < act[i].first)
            {
                ctr++;
                prev = act[i].second;
            }
        }
        
        return ctr;
        
    }
};