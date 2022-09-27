class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        int prefix_mx[n];
        int suffix_mx[n];
        
        int mx = 0;
        for(int i=0; i<n; i++)
        {
            mx = max(mx, height[i]);
            prefix_mx[i] = mx;
        }
        
        mx = 0;
        for(int i=n-1; i>=0; i--)
        {
            mx = max(mx, height[i]);
            suffix_mx[i] = mx;
        }
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            ans += min(prefix_mx[i], suffix_mx[i]) - height[i];
        }
        
        return ans;
    }
};