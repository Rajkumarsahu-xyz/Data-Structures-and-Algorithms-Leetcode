class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) 
    {
        int n = points.size();
        sort(points.begin(), points.end());
        
        int mx = 0;
        for (int i = 1; i < n; i++) 
        {
            mx = max(mx, points[i][0] - points[i-1][0]);
            cout << mx;
        }
        
        return mx;
    }
};