class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        int mx = 0, n = candies.size();
        vector<bool> ans;
        for(int i=0; i<n; i++)
        {
            mx = max(mx, candies[i]);
        }
        
        for(int i=0; i<n; i++)
        {
            ans.push_back(candies[i]+extraCandies >= mx);
        }
        
        return ans;
    }
};