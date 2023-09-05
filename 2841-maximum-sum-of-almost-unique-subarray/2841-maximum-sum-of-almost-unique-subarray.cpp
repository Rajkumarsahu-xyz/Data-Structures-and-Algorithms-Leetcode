class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) 
    {
        int n = nums.size();
        
        int i=0, j=0;
        unordered_map<int, int> mp;
        long long sum = 0;
        long long mx = 0;
        
        while(j<n)
        {
            // cout << i << " " << j << endl;
            if(j-i+1 <= k)
            {
                sum += nums[j];
                mp[nums[j]]++;
            }
            
            if(j-i+1 == k)
            {
                // cout << mp.size() << endl;
                if(mp.size() >= m)
                    mx = max(mx, sum);
                // cout << mx << endl;
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            
            j++;
            
        }
        
        return mx;
    }
};