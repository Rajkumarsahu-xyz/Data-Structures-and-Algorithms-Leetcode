class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long int ans = 0;
        long long int ctr = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
                ctr++;
            else
            {
                ans += (ctr*(ctr+1)/2);
                ctr = 0;
            }
        }

        if(ctr > 0)
        {
            ans += (ctr*(ctr+1)/2);
        }

        return ans;
    }
};