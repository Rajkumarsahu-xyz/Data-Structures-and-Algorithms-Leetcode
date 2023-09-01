class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> ans(n+1);
        ans[0] = 0;
        
        for(int i = 1; i<n+1; ++i)
        {
            ans[i] = __builtin_popcount(i);
        }
        
        return ans;
    }
};