class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) 
    {
        unordered_map<int, int> mp;
        int ans = 0;
        
        for(auto x: nums)
        {
            mp[x]++;
        }
        
        for(auto x: nums)
        {
            if(mp.find(x-diff) != mp.end()  &&  mp.find(x-(2*diff)) != mp.end())
            {
                ans++;
                mp[x]--, mp[x-diff]--, mp[x-(2*diff)]--;
            }
        }
        return ans;
    }
};