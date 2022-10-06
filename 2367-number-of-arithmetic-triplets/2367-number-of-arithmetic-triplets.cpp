class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) 
    {
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto x: nums)
        {
            if(mp.find(x-diff) != mp.end()  &&  mp.find(x-(2*diff)) != mp.end())
                ans = ans + mp[x-diff]* mp[x-(2*diff)];
            
            mp[x]++;
        }
        return ans;
    }
};