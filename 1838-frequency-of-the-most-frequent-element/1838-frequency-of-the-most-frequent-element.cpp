class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
       long long int left=0, right=0, n=nums.size(), dist=0, best=0;
        sort(nums.begin(), nums.end());
        
        while(right < n)
        {
            if(right>0 and nums[right]!=nums[right-1])
            {
                dist += (right-left)*(nums[right]-nums[right-1]);
            }
            right++;
            
            while(dist>k)
            {
                dist-=(nums[right-1]-nums[left]);
                left++;
            }
            best = max(best,right-left);
        }
        
        return best;
    }
};