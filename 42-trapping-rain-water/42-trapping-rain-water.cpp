class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        int ans = 0;
        
        int l=0, r=n-1;
        int left_mx=0, right_mx=0;
        while(l <= r)
        {
            if(height[l] <= height[r])
            {
                if(height[l] >= left_mx)
                    left_mx = height[l];
                else
                    ans += left_mx - height[l];
                l++;
            }
            
            else
            {
                if(height[r] >= right_mx)
                    right_mx = height[r];
                else
                    ans += right_mx - height[r];
                r--;
            }
        }
        
        return ans;
    }
};