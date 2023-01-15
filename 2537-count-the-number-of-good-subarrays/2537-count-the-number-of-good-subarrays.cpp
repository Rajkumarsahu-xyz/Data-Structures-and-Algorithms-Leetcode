class Solution {
public:
    long long countGood(vector<int>& nums, int k) 
    {
        long long n = nums.size();
        long long i=0, j=0, ctr=0;
        unordered_map<long long, long long> mp;
        long long c = 0;
        
        while(j<n)
        {
            if (mp[nums[j]] > 0) 
            {
                c += mp[nums[j]];
            }
            mp[nums[j]]++;
            while (i<=j && c>=k)
            {
                if (mp[nums[i]] > 1)
                {
                    c -= (mp[nums[i]] - 1);
                }
                mp[nums[i]]--;
                i++;
            }
            ctr += (j-i+1);
            j++;
        }
        
        return  (n * (n + 1) / 2) - ctr;
    }
};