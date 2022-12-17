class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) 
    {
        int m = int(nums1.size()), n = int(nums2.size());
        int ans = 0;
        
        // Iterate over nums1 and find insertion position to nums2.
        for (int i = 0; i < m; ++i) 
        {
            int k = nums2.rend() - lower_bound(nums2.rbegin(), nums2.rend(), nums1[i]);
            if (k > 0) 
            {
                ans = max(ans, k - i - 1);
            }
        }
        
        return ans;
    }
};