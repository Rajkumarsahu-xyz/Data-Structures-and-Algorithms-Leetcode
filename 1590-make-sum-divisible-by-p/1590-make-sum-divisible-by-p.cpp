class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        int n = nums.size();
        int sum = 0;
        vector<int> prefixSum;
        for(int i=0; i<n; i++)
        {
            sum = (sum + nums[i]) % p;
            prefixSum.push_back(sum);
        }
        
        if(sum%p == 0)
            return 0;
        
        int rem = sum % p;
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int mn = n;
        for(int i=0; i<n; i++)
        {
            int needed = (prefixSum[i] - rem + p) % p;
            if(mp.find(needed) != mp.end())
            {
                int k = mp[needed];
                mn = min(mn, i-k);
            }
            
            mp[prefixSum[i]] = i;
        }
        
        if(mn == n)
            return -1;
        
        return mn;
    }
};