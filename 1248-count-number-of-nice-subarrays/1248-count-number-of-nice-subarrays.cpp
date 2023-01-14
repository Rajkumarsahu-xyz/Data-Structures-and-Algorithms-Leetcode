class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int i=0, j=0, ctr=0, o=0;
        unordered_map<int, int> mp;
        int ans = 0;
        while(j<n)
        {
            if(nums[j]%2 == 1)
            {
                o++;
                ctr = 0;
            }
            
            while(o == k)
            {
                ctr++;
                if(nums[i]%2 == 1)
                {
                    o--;
                }
                i++;
            }
            j++;
            ans += ctr;
        }
        
        return ans;
        
    }
};