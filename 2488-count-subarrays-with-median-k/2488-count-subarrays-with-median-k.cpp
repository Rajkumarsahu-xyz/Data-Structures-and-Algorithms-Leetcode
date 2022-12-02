class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int indk = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == k) break;
            
            indk++;
        }
        
        cout << indk << endl;
        
        unordered_map<int, int> mp;
        mp[0]++;
        int diff = 0;
        for(int i=indk+1; i<nums.size(); i++)
        {
            if(nums[i] > k)
                diff++;
            else 
                diff--;
            
            mp[diff]++;
        }
        
        int ctr = mp[0] + mp[1];
        
        diff = 0;
        for(int i=indk-1; i>=0; i--)
        {
            if(nums[i] > k)
                diff++;
            else
                diff--;
            
            ctr += (mp[0-diff] + mp[1-diff]);
        }
        
        return ctr;
    }
};