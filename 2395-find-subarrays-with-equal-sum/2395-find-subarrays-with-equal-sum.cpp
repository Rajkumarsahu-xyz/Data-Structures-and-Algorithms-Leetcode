class Solution {
public:
    bool findSubarrays(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size()-1; i++)
        {
            mp[nums[i]+nums[i+1]]++;
        }
        
        for(auto x : mp)
        {
            if(x.second > 1)
                return true;
        }
        
        return false;
    }
};