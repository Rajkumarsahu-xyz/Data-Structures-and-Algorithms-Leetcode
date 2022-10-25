class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;
        int sum = 0, count = 0;
        mp[sum] = 1;
        
        for(auto x : nums)
        {
            sum += x;
            if(mp.find(sum - k) != mp.end())
            {
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};