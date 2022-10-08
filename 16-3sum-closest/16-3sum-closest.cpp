class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int sum = nums[0]+nums[1]+nums[2];
        int mn = INT_MAX;
        
        for(int i=0; i<nums.size()-2; i++)
        {
            for(int j=i+1, k=nums.size()-1; j<k; )
            {
                int cur_sum = nums[i]+nums[j]+nums[k];
                if(abs(cur_sum - target) < mn)
                {
                    mn = abs(cur_sum - target);
                    sum = cur_sum;
                }
                
                if(cur_sum == target)
                    return cur_sum;
                else if(cur_sum < target)
                    j++;
                else
                    k--;
                
                while(j<k  &&  nums[j]==nums[j+1]) j++;
                while(j<k  &&  nums[k]==nums[k-1]) k--;
            }
        }
        
        return sum;
    }
};