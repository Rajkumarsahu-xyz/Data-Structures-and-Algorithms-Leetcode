class Solution {
public:
    
    int subarrays(vector<int>&nums, int k)
    {
        int i=0, j=0, ctr=0, n=nums.size();
        unordered_map<int, int> mp;
        
        while(j<n)
        {
            mp[nums[j]]++;
            while(i<=j && mp.size()>k)
            {
                if(mp[nums[i]] == 1)
                    mp.erase(nums[i]);
                else
                    mp[nums[i]]--;
                
                i++;
            }
            
            ctr += (j-i+1);
            j++;
        }
        
        return ctr;
    }
    
    
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return (subarrays(nums, k) - subarrays(nums, k-1));
    }
};