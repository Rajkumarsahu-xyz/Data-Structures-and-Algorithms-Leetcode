class Solution {
public:
    
    bool partition(vector<int>& nums, int n, int s, vector<bool>& prev)
    {
        prev[0] = true;
        
        if(nums[0] <= s)
            prev[nums[0]] = true;
    
        for(int ind = 1; ind<n; ind++)
        {
            vector<bool> curr(s+1, false);
            curr[0] = true;
            for(int target= 1; target<=s; target++)
            { 
                bool notTaken = prev[target];

                bool taken = false;
                if(nums[ind]<=target)
                    taken = prev[target-nums[ind]];
        
                curr[target] = notTaken || taken;
            }
            prev = curr;
        }
    
        return prev[s];
    }
    
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int s = 0;
        for(int i=0; i<n; i++)
        {
            s += nums[i];
        }
        
        if(s%2 != 0)
            return false;
        
        else
        {
            vector<bool> prev((s/2)+1, false); 
            return partition(nums, n, s/2, prev);
        }
    }
};